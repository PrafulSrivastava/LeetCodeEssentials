#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
// Q5 : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
class Q5 {
public:
	static int count_of_neagtive_from(pair<int,int> &max, pair<int,int> pos, int rows) {
		int cnt = (rows - pos.first + 1) * (max.second - pos.second + 1);
		max.first = pos.first + 1 ;
		max.second = pos.second - 1;
		return cnt;
	}
	static int countNegatives(vector<vector<int>>& grid) {
		int cnt = 0;
		pair<int, int> max = { 0 ,grid[0].size() -1 };
		for (int i = max.first; i < grid.size(); i++) {
			for (int j = 0; j <= max.second; j++) {
				if (grid[i][j] < 0) {
					cnt += count_of_neagtive_from(max, { i,j } , grid.size()-1);
					break;
				}
			}
		}
		return cnt;

	}
	static void init() {
		vector<vector<int>> grid = { {4,3,2,-1}
									,{3,2,1,-1}
									,{1,1,-1,-2}
									,{-1,-1,-2,-3} };
		auto res = countNegatives(grid);
		cout << "Count of negative numbers : " << res << endl;
	}
};