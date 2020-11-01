#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
// Q7 : https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
class Q7 {
public:
	static void increment_by_1(int r,int c, vector<vector<int>>& v) {
		for (int i = 0; i < v.size(); i++) {
			v[i][c] = v[i][c] + 1;
		}
		for (int i = 0; i < v[0].size(); i++) {
			v[r][i] = v[r][i] + 1;
		}
	}
	static int oddterms(vector<vector<int>>& v) {
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[0].size(); j++) {
				if (v[i][j] & 1) {
					cnt++;
				}
			}
		}
		return cnt;
	}
	static int oddCells(int n, int m, vector<vector<int>>& indices) {
		vector<vector<int>> vec(n, vector<int>(m, 0));
		for (int i = 0; i < indices.size(); i++) {
			increment_by_1(indices[i][0], indices[i][1], vec);
		}

		int cnt = oddterms(vec);
		return cnt;
	}
	static void init() {
		int n = 2, m = 3;
		vector<vector<int>> indices = { {0,1},{1,1} };
		auto res = Q7::oddCells(n,m, indices);
		cout << "Count of odd values : " << res << endl;
	}
};