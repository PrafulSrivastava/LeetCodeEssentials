#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// Q2 : https://leetcode.com/problems/decompress-run-length-encoded-list/
class Q2 {
public:
    static vector<int> decompressRLElist(vector<int>& nums) {
		vector<int> res;
		for (int i = 0; i < nums.size(); i+=2) {
			int temp = nums[i];
			while(temp--)
				res.push_back(nums[i+1]);
		}
		return res;
    }
	static void init() {
		vector<int> nums = { 1,2,3,4 };
		auto res = Q2::decompressRLElist(nums);
		for (auto x : res) {
			cout << x << " ";
		}
	}

};