#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

using namespace std;
// Q24 : https://leetcode.com/problems/day-of-the-week/
class Q24 {
public:
	static int minCostToMoveChips(vector<int>& position) {
		int cost_even = 0;
		int cost_odd = 0;
		for (auto x : position) {
			if (x & 1) {
				cost_odd++;
			}
			else {
				cost_even++;
			}
		}
		return (cost_even > cost_odd) ? cost_odd : cost_even;
	}
	static void init() {
		vector<int> position = { 1, 1000000 };
		auto res = Q24::minCostToMoveChips(position);
		cout << "Result : " << res << endl;
	}
};