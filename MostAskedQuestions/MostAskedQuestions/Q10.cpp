#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
// Q10 : https://leetcode.com/problems/flipping-an-image/
class Q10 {
public:
	static void invert(vector<vector<int>>& A) {
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A[0].size(); j++) {
				A[i][j] ^= 1;
			}
		}
		for (auto x : A) {
			for (auto y : x) {
				cout << y << " ";
			}
			cout << endl;
		}
	}
	static void swap(int &a, int &b) {
		int c = a;
		a = b;
		b = c;
	}
	static void flip(vector<vector<int>>& A) {
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A[0].size()/2; j++) {
				swap(A[i][j], A[i][A[0].size() - j - 1]);
			}
		}
		for (auto x : A) {
			for (auto y : x) {
				cout << y << " ";
			}
			cout << endl;
		}
	}
	static vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		flip(A);
		invert(A);
		return A;
	}
	
	static void init() {
		vector<vector<int>> A = { {1,1,0},{1,0,1},{0,0,0} };
		auto res = Q10::flipAndInvertImage(A);
		for (auto x : res) {
			for (auto y : x) {
				cout << y << " ";
			}
			cout << endl;
		}
	}
};