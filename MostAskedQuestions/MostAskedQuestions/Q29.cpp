#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
// Q29 : https://leetcode.com/problems/fair-candy-swap/
class Q29 {
public:
    static int find_in_vec(int n, vector<int> & vec) {// 1 lf3
        int f = 0;
        int l = vec.size()-1;

        int mid = (f + l) / 2;
        int pos = -1;
        while (f <= l) {
            if (n == vec[mid]) {
                pos = mid;
                break;
            }
            if (n < vec[mid]) {
                l = mid - 1;
            }
            if (n > vec[mid]) {
                f = mid + 1;
            }         
            mid = (f + l) / 2;
        }
        return pos;
    }
    static vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum_a = 0;
        int sum_b = 0;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        vector<int> res(2, 0);
        for (auto x : A) {
            sum_a += x;
        }
        for (auto x : B) {
            sum_b += x;
        }
        int equal_sum = (sum_a + sum_b) / 2;
        int diff = sum_a - sum_b;
        bool give_or_take = false;
        if (diff < 0) {
            give_or_take = true;
        }
        //A = [2,4] , B = [1,2,5]
        int i = 0;
        while (true) {
            if (give_or_take) {
                int b_to_give = sum_b - equal_sum;// 4 - 3
                int pos = find_in_vec(b_to_give+ A[i], B);
                if (pos >= 0) {
                    res[0] = A[i];
                    res[1] = B[pos];
                    break;
                }
                i++;
                if (i >= A.size()) {
                    break;
                }
            }
            else {
                int a_to_give = sum_a - equal_sum;
                int pos = find_in_vec(a_to_give + B[i], A);
                if (pos >= 0) {
                    res[0] = A[pos];
                    res[1] = B[i];
                    break;
                }
                i++;
                if (i >= B.size()) {
                    break;
                }
            }
            
        }

        return res;
    }
    static void init() {
        vector<int> A = { 32, 38, 8, 1, 9 };
        vector<int> B = { 68, 92 };
        auto res = Q29::fairCandySwap(A, B);
        for (auto x : res) {
            cout << x << " ";
        }
    }
};
