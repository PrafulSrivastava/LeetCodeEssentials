#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
// Q25 : https://leetcode.com/problems/toeplitz-matrix/
class Q25 {
public:
	static bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		for (int i = 0; i < matrix.size() - 1; i++) {
			for (int j = 0; j < matrix[0].size() - 1; j++) {
				if (matrix[i][j] != matrix[i + 1][j + 1]) {
					return false;
				}
			}
		}
		return true;
	}
	static void init() {
		vector<vector<int>> matrix = { {1,2}, {2,2} };
		auto res = Q25::isToeplitzMatrix(matrix);
		cout << "Result : " << res << endl;
	}
};