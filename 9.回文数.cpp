/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// 1000021
class Solution {
  public:
    bool isPalindrome(int x) {
        int n, next_n, start, end, end_zero, step;
        if (x < 0)
            return false;
        if (x == 0)
            return true;

        while (x != 0) {
            n = log10(x);
            if (n == 0)
                return true;

            step = pow(10, n);
            start = x / step;
            end = x % 10;

            if (start != end)
                return false;

            x = x % step;
            x /= 10;
            if (x == 0)
                return true;
            next_n = log10(x);
            end_zero = pow(10, n - next_n - 2);
            if (x % end_zero != 0)
                return false;

            x /= end_zero;
        }
        return true;
    }
};
// @lc code=end
