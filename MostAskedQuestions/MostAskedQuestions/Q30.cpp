#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
// Q30 : https://leetcode.com/problems/move-zeroes/
class Q30 {
public:
    static void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for (auto i = nums.begin(); i != nums.end(); ++i) {
            if (*i == 0) {
                nums.erase(i);
                i--;
                cnt++;
            }
        }
        while (cnt--) {
            nums.push_back(0);
        }
        for (auto x : nums) {
            cout << x << " " ;
        }
    }
    static void init() {
        vector<int> nums = { 32, 38, 0, 0, 9 };
        Q30::moveZeroes(nums);
    }
};
