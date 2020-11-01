#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

// Q13 : https://leetcode.com/problems/array-partition-i/
class Q13 {
public:
	static int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int sum = 0;
		for (int i = 0; i < nums.size(); i += 2) {
			sum += nums[i];
		}
		return sum;
	}
	static void init() {
		vector<int> A = { 1,4,3,2 };
		auto res = Q13::arrayPairSum(A);
		cout << "Sum : " << res << endl;
	}
};