#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

using namespace std;

struct comp {
	bool operator()(const int& a, const int& b) const {
		return a < b;
	}
};

// Q21 : https://leetcode.com/problems/minimum-absolute-difference/
class Q21 {
public:
	static vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		vector<vector<int>> res;
		sort(arr.begin(), arr.end(), comp());
		int min = arr[1] - arr[0];
		for (int i = 1; i < arr.size() -1; i++) {
			int diff = arr[i + 1] - arr[i];
			if (diff < min) {
				min = diff;
			}
		}
		for (int i = 0; i < arr.size() - 1; i++) {
			int diff = arr[i + 1] - arr[i];
			if (diff == min) {
				res.push_back({arr[i],arr[i+1]});
			}
		}
		return res;
	}
	static void init() {
		vector<int> A = { 4,2,1,3 }; 
		auto res = Q21::minimumAbsDifference(A);
		for (auto x : res) {
			for (auto y : x) {
				cout << y << " ";
			}
			cout << endl;
		}
	}
};