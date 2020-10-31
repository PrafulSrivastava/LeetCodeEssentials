#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
// Q3 : https://leetcode.com/problems/minimum-time-visiting-all-points/
class Q4 {
public:
	static int distance(pair<int, int>x, pair<int, int>y) {
		return (abs(x.first - y.first) > abs(x.second - y.second)) ? abs(x.first - y.first) : abs(x.second - y.second);
	}
	static int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int time = 0;
		if (!points.empty()) {
			for (int i = 0; i+1 < points.size(); i++) {
				time += distance({ points[i][0], points[i][1] }, { points[i + 1][0], points[i + 1][1] });
			}
		}
		return time;
	}

	static void init() {
		vector<vector<int>> points = { {1,1},{3,4},{-1,0} };
		auto res = Q4::minTimeToVisitAllPoints(points);
		cout << "Minnimum time: " << res << endl;
	}
};