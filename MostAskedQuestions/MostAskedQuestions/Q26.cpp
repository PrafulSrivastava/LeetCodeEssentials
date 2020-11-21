#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
// Q26 : https://leetcode.com/problems/duplicate-zeros/
class Q26 {
public:
	static void duplicateZeros(vector<int>& arr) {
		
		for (auto i = arr.begin(); i != arr.end(); i++) {
			if (*i == 0) {
				if(i + 1 != arr.end())
					i++;
				i = arr.insert(i, 0);
				auto end_arr = arr.begin() + (arr.size() - 1);
				arr.erase(end_arr);
			}
		}
		for (auto x : arr) {
			cout << x << " ";
		}
	}
	static void init() {
		vector<int> arr = { 0,0,0,0,0 };
		Q26::duplicateZeros(arr);
	}
};