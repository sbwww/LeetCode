/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int days[14] = {0,   0,   31,  59,  90,  120, 151,
                    181, 212, 243, 273, 304, 334, 365};
    int isLeap(int year) {
        if (year % 400 == 0)
            return 1;
        if (year % 100 == 0)
            return 0;
        if (year % 4 == 0)
            return 1;
        return 0;
    }
    int dayOfYear(string date) {
        int year, month, day;
        int ans = 0;
        year = stoi(date.substr(0, 4));
        month = stoi(date.substr(5, 2));
        day = stoi(date.substr(8, 2));
        ans = days[month] + day;
        if (month > 2)
            ans += isLeap(year);
        return ans;
    }
};
// @lc code=end
