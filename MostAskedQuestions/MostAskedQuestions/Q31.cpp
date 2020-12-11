#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
// Q31 : https://leetcode.com/problems/max-consecutive-ones/
class Q31 {
public:
    static int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0;
        int max = 0;
        for (auto x : nums) {
            if (x != 0) {
                sum += 1;
            }
            else {
                if (max < sum) {
                    max = sum;
                }
                sum = 0;
            }
        }

        if (max < sum) {
            max = sum;
        }
        return max;
    }
    static void init() {
        vector<int> nums = { 1,1,0,1,1,1 };
        auto res = Q31::findMaxConsecutiveOnes(nums);
        cout << "Result : " << res << endl;
    }
};