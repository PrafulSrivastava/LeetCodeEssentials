#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Q1 {
public:
	static int find_in_paired_vector(vector<pair<int, int>>& mp, int i) {
		//cout << "Rec : " << i << endl;
		for (auto x : mp) {
			cout << x.first << " ";
			if (i == x.first) {
				//cout << "Return : " << x.second << endl;
				return x.second;
			}
				
		}
		return -1;
	}
	static vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> cpy_nums(nums.size());
		vector<pair<int, int>> mp;
		copy(nums.begin(), nums.end(), cpy_nums.begin());
		sort(cpy_nums.begin(), cpy_nums.end());
		int i = 0;
		int temp = 0;
		int dup = 0;
		for (auto x : cpy_nums) {
			if (x > temp) {
				i++;
				//cout << " Insert " << x << " " << i - 1 + dup << endl;
				mp.push_back(pair<int, int>(x, i - 1 + dup));
			}
			else if (x == temp) {
				dup++;
				//cout << " Insert " << x << " " << i<< endl;
				mp.push_back(pair<int, int>(x, i));
			}
			
			temp = x;
		}
		i = 0;
		for (auto x : mp) {
			int t = find_in_paired_vector(mp, nums[i]);
			if (t >= 0) {
				cpy_nums[i] = t;
			}
			
			i++;
		}
		return cpy_nums;
	}
	static void begin() {
		vector<int> nums = { 5,0,10,0,10,6 };
		auto res = Q1::smallerNumbersThanCurrent(nums);
		for (auto x : res) {
			cout << x << " ";
		}
	}


};