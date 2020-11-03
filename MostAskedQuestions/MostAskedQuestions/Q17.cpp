#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

// Q17 : https://leetcode.com/problems/relative-sort-array/
class Q17 {
public:
	static int min_mem(vector<int> arr2) {
		int min = arr2[0];
		for (auto x : arr2) {
			if (x < min) {
				min = x;
			}
		}
		return min;
	}
	static int max_mem(vector<int> arr2) {
		int max = arr2[0];
		for (auto x : arr2) {
			if (x > max) {
				max = x;
			}
		}
		return max;
	}
	static int in_arr2(vector<int>& arr2 , int n) {
		for (int i = 0; i < arr2.size(); i++) {
			if (arr2[i] == n) {
				return i;
			}
		}
		return -1;
	}
	static vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		int len_a2 = arr2.size();
		int replica_added = 0;
		int min = min_mem(arr2);
		int max = max_mem(arr2);
		vector<int> cpy_arr2(arr2.size());
		copy(arr2.begin(), arr2.end(), cpy_arr2.begin());
		unordered_map<int, bool> mp;
		for (auto x : arr2) {
			mp.insert(pair<int, bool>(x, false));
		}
		for (auto x : arr1) {
			auto it_begin = arr2.begin();
			int pos = in_arr2(cpy_arr2, x);
			if (pos >= 0) {
				if (mp[x]) {
					replica_added++;
					arr2.insert(it_begin+pos , arr2[pos]);
				}
				else {
					mp[x] = true;
				}
				
			}
			else {
				arr2.insert(it_begin + len_a2+replica_added, x);
			}
		}
		sort(arr2.begin() + len_a2 + replica_added, arr2.end());
		return arr2;
	}
	static void init() {
		vector<int> arr1 = { 2, 21, 43, 38, 0, 42, 33, 7, 24, 13, 12, 27, 12, 24, 5, 23, 29, 48, 30, 31 },
			arr2 = { 2, 42, 38, 0, 43, 21 };
		auto res = Q17::relativeSortArray(arr1, arr2);
		for (auto x : res) {
			cout << x << " ";
		}
	}
};