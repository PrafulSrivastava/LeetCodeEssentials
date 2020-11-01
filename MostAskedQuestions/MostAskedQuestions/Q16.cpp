#pragma once
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

// Q16 : https://leetcode.com/problems/sort-array-by-parity-ii/
class Q16 {
public:
	static void swap(int& a, int& b) {
		int c = a;
		a = b;
		b = c;
	}
	static vector<int> sortArrayByParityII(vector<int>& A) {
		stack<int> misplaced_even;
		stack<int> misplaced_odd;
		for (int i = 0; i < A.size(); i++) {
			if (i & 1) {
				if (!(A[i] & 1)) {
					if(misplaced_odd.empty())
						misplaced_even.push(i);
					else {
						swap(A[i], A[misplaced_odd.top()]);
						misplaced_odd.pop();
					}
						
				}
			}
			else {
				if (A[i] & 1) {
					if (misplaced_even.empty())
						misplaced_odd.push(i);
					else {
						swap(A[i], A[misplaced_even.top()]);
						misplaced_even.pop();
					}

				}
			}
			
		}
		return A;

	}
	static void init() {
		vector<int> A  = { 4,2,5,7 };
		auto res = Q16::sortArrayByParityII(A);
		for (auto x : res) {
			cout << x << " ";
		}
	}
};