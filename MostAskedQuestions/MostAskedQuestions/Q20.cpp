#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

using namespace std;

struct comp {
	bool operator()(const string &a, const string &b) const {
		return a.length() < b.length();
	}
};

// Q20 : https://leetcode.com/problems/find-common-characters/
class Q20 {
public:
	static vector<string> commonChars(vector<string>& A) {
		vector<string> chars;
		
		sort(A.begin(), A.end(), comp());
		copy(A.begin(), A.end(), A.begin());
		auto start = A.begin();
		sort(A[0].begin(), A[0].end());
		for (auto x : A[0]) {
			bool flag = true;
			start = A.begin();
			start++;
			while(start != A.end()) {
				auto pos = start->find(x);
				if (pos == string::npos) {
					flag = false;
					break;
				}
				else {
					(*start)[pos] = '#';
				}
				start++;
			}
			if (flag) {
				string s = "";
				s.push_back(x);
				chars.push_back(s);
			}
			start = A.end();
		}
		return chars;
	}
	static void init() {
		vector<string> A = { "cooasasl","locka","cookss" }; // cloo clko ckoo
		auto res = Q20::commonChars(A);
		for (auto x : res) {
			cout << x << " ";
		}
	}
};