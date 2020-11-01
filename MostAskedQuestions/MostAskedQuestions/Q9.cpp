#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
// Q9 : https://leetcode.com/problems/lucky-numbers-in-a-matrix/
class Q9 {
public:
	static bool is_lucky(vector<vector<int>>& matrix , int r, int c) {
		int min, max;
		min = matrix[r][c];
		for (int i = 0; i < matrix[0].size(); i++) {
			if (matrix[r][i] < min) {
				return false;
			}
		}

		max = matrix[r][c];
		for (int i = 0; i < matrix.size(); i++) {
			if (matrix[i][c] > max) {
				return false;
			}
		}
		return true;
	}
	static vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		vector<int> res;
		map<int, bool> mp_row;
		for (int i = 0; i < matrix.size(); i++) {
			mp_row.insert(pair<int, bool>(i, true));
		}
		map<int, bool> mp_col;
		for (int j = 0; j < matrix[0].size(); j++) {
			mp_col.insert(pair<int, bool>(j, true));
		}

		for (int i = 0; i < matrix.size(); i++) {
			if (mp_row[i]) {
				for (int j = 0; j < matrix[0].size(); j++) {
					if (mp_col[j]) {
						if (is_lucky(matrix, i, j)) {
							mp_row[i] = false;
							mp_col[j] = false;
							res.push_back(matrix[i][j]);
						}
					}

				}
			}
			
		}
		return res;
	}
	static void init() {
		vector<vector<int>> matrix = { {3,7,8},{9,11,13},{15,16,17} };
		auto res = Q9::luckyNumbers(matrix);
		for (auto x : res) {
			cout << x << " ";
		}
	}
};