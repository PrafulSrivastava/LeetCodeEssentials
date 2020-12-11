#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
// Q32 : https://leetcode.com/problems/majority-element/
class Q32 {
public:
    static int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int limit = size / 2;
        int max = 0;
        int num = 0;
        unordered_map<int, int> mp;
        for (auto x : nums) {
            mp[x]++;
        }
        for (int i = 0; i < size; i++) {
            if (max < mp[nums[i]]) {
                max = mp[nums[i]];
                num = nums[i];
            }
        }
        return num;
    }
    static void init() {
        vector<int> nums = { 2,2,1,1,1,2,2 };
        auto res = Q32::majorityElement(nums);
        cout << "Result : " << res << endl;
    }
};