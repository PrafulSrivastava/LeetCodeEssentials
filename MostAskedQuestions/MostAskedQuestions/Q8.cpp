#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
// Q8 : https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
class Q8 {
public:
	static  vector<int> sumZero(int n) {
		vector<int> res;
		if (n & 1) {
			res.push_back(0);
		}
		for (int i = 1; i <= n / 2; i++) {
			res.push_back(i);
			res.push_back(-1*i);
		}
		return res;
	}
	static void init() {
		int n = 5;
		auto res = Q8::sumZero(n);
		for (auto x : res) {
			cout << x << " ";
		}
	}
};