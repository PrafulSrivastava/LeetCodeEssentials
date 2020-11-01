#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
// Q11 : https://leetcode.com/problems/sort-array-by-parity/
class Q11 {
public:
	static vector<int> sortArrayByParity(vector<int>& A) {
		vector<int> eres;
		vector<int> ores;
		for (auto x : A) {
			if (x & 1) {
				ores.push_back(x);
			}
			else {
				eres.push_back(x);
			}
		}
		copy(eres.begin(), eres.end(), A.begin());
		copy(ores.begin(), ores.end(), A.begin()+eres.size());
		return A;
	}

	static void init() {
		vector<int> A = { 3,1,2,4 };
		auto res = Q11::sortArrayByParity(A);
		for (auto x : res) {
			cout << x << " ";			
		}
	}
};