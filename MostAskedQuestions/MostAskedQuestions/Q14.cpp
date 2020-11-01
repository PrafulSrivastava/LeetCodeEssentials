#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

// Q14 : https://leetcode.com/problems/height-checker/
class Q14 {
public:
	static int heightChecker(vector<int>& heights) {
		vector<int> cpy(heights.size());
		int c = 0;
		copy(heights.begin(), heights.end(), cpy.begin());
		sort(cpy.begin(), cpy.end());
		for (int i = 0; i < heights.size(); i++) {
			if (cpy[i] != heights[i]) {
				c++;
			}
		}
		return c;
	}
	static void init() {
		vector<int> heights = { 1,4,3,2 };
		auto res = Q14::heightChecker(heights);
		cout << "Change Required : " << res << endl;
	}
};