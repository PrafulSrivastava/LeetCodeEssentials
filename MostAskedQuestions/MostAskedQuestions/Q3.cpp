#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
// Q3 : https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
class Q3 {
public:
	static bool iseven(int k) {
		if (k & 1) {
			return false;
		}
		return true;
	}
	static int digits(int n) {
		return (n > 0) ? ((int)log10(n)) +1 : 1;
	}
	static int findNumbers(vector<int>& nums) {
		int cnt = 0;
		for (auto x : nums) {
			if (iseven(digits(x))) {
				cnt++;
			}
		}
		return cnt;
    }

	static void init() {
		vector<int> nums = { 12,345,2,6,7896 };
		auto res = Q3::findNumbers(nums);
		cout << "Count of numbers with even digits: " << res << endl;
	}
};