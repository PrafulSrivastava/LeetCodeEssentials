#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
struct comp_rev {
    bool operator()(const int& a, const int& b) const {

        return a > b;
    }
};
using namespace std;
// Q27 : https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/submissions/
class Q27 {
public:
    static vector<int> get_count_of_smallest_char(vector<string>& str) {
        vector<int> cnt(str.size());
        for (int i = 0; i < str.size(); i++) {
            int c = 0;
            char min = str[i][0];
            for (auto x : str[i]) {
                if (min > x) {
                    min = x;
                    c = 1;
                }
                else if (x == min) {
                    c++;
                }
            }
            cnt[i] = c;
        }
        return cnt;
    }
    static vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res(queries.size());
        auto query_cnt = get_count_of_smallest_char(queries);
        auto wrds_cnt = get_count_of_smallest_char(words);
        queries.clear();
        words.clear();
        sort(wrds_cnt.begin(), wrds_cnt.end(), comp_rev());
        int i = 0;
        for (auto x : query_cnt) {
            int f = 0;
            int l = wrds_cnt.size() - 1;
            while (true) {
                int mid = (f + l) / 2;
                if (x < wrds_cnt[mid]) {
                    f = mid + 1;
                }
                else {
                    l = mid;
                }
                if (f >= l) {
                    break;
                }
            }

            res[i] = f;
            i++;
        }
        return res;
    }
    static void init() {
        vector<string> queries = { "cbd" };
        vector<string> words = { "zaaaz" };
        auto res = Q27::numSmallerByFrequency(queries, words);
        for (auto x : res) {
            cout << x << " ";
        }
    }
};