#pragma once
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second < b.second;
	}
};
// Q15 : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
class Q15 {
public:
	
	static vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		set<pair<int, int>, comp> mp;
		vector<int> res;
		for (int i = 0; i < mat.size(); i++) {
			cout << "i :" << i << endl;
			bool flag = true;
			for (int j = 0; j < mat[0].size(); j++) {
				if (!(mat[i][j])) {
					flag = false;
					cout << "Insert : " << i << " " << j << endl;
					mp.insert(pair<int,int>(i,j));
					break;
				}
			}
			if (flag) {
				mp.insert(pair<int, int>(i, mat[0].size()));
			}
		}
		
		for (auto x : mp) {
			cout << x.first << " " << x.second << endl;
			if (!(k--)) {
				break;
			}
			res.push_back(x.first);
		}
		if (res.empty()) {
			res.push_back(0);
		}
		return res;
	}
	
	static void init() {
		vector<vector<int>> mat = { {1,0},{1,0},{1,0},{1,1} };
		int k = 4;
		auto res = Q15::kWeakestRows(mat, k);
		for (auto x : res) {
			cout << x << " ";
		}
	}
};