#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
#define f0  0
#define f1  1
// Q19 : https://leetcode.com/problems/fibonacci-number/
class Q19 {
public:
	static int fib(int N) {
		int res = 0;
		int a = f0;
		int b = f1;
		if (N == 0) {
			return f0;
		}
		if (N == 1) {
			return f1;
		}
		N -= 1;
		while (N--) {
			res = (a + b);
			a = b;
			b = res;
		}
		return res;
	}
	static void init() {
		int n = 5;
		auto res = Q19::fib(n);
		cout << "Count : " << res << endl;
	}
};