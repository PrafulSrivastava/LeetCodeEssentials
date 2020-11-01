#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
// Q6 : https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
class Q6 {
public:
	static int max_to_right(vector<int>& arr, int pos) {
		int max = arr[pos];
		int max_pos = pos;
		for (int i = pos + 1; i < arr.size(); i++) {
			if (arr[i] > max) {
				max = arr[i];
				max_pos = i;
			}
		}
		arr[pos - 1] = max;
		return max_pos;
	}
	static vector<int> replaceElements(vector<int>& arr) {
		int cur_max_pos = -1;
		for (int i = 0; i < arr.size()-1; i++) {
			if (cur_max_pos > i) {
				arr[i] = arr[cur_max_pos];
			}
			else
				cur_max_pos = max_to_right(arr, i + 1);
		}
		arr[arr.size() - 1] = -1;
		return arr;
	}

	static void init() {
		vector<int> nums = { 17,18,5,4,6,1 };
		auto res = Q6::replaceElements(nums);
		for (auto x : res) {
			cout << x << " ";
		}
	}
};