#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

// Q18 : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
class Q18 {
public:
	static bool is_possible(string chars, string str) {
		if (str.length() > chars.length()) {
			return false;
		}
		for (auto x : str) {
			auto pos = chars.find(x);
			if (pos != string::npos) {
				chars[pos] = 1;
			}
			else {
				return false;
			}
		}
		return true;
	}
	static int countCharacters(vector<string>& words, string chars) {
		int res = 0;
		for (auto x : words) {
			if (is_possible(chars, x)) {
				res += x.length();
			}
		}
		return res;
	}
	static void init() {
		vector<string> words = { "hello", "world", "leetcode" };
		string chars = "welldonehoneyr";
		auto res = Q18::countCharacters(words,chars);
		cout << "Count : " << res << endl;
	}
};