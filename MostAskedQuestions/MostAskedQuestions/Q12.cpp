#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

// Q12 : https://leetcode.com/problems/squares-of-a-sorted-array/
class Q12 {
public:
	static vector<int> sortedSquares(vector<int>& A) {
		vector<int> res;
		int i;
		int pos = A.size();
		bool flag = true;
		for(i =0;i<A.size();i++ ){
			if (A[i] < 0) {
				A[i] *= -1;
			}
			res.push_back(pow(A[i], 2));
		}
		sort(res.begin(),res.end());
		return res;
	}
	static void init() {
		vector<int> A = { -2,0 ,1 ,2, 3, 4 ,5, 6, 7, 8, 9 };
		auto res = Q12::sortedSquares(A);
		for (auto x : res) {
			cout << x << " ";
		}
	}
};