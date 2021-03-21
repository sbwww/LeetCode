/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string ans;
    void add(int n, char c) {
        for (int i = 0; i < n; ++i) {
            ans.push_back(c);
        }
    }
    string intToRoman(int num) {
        int tmp = num;

        int n = log10(tmp) + 1;
        switch (n) {
        case 4:
            add(tmp / 1000, 'M');
            tmp %= 1000;

        case 3:
            if (tmp / 900)
                ans += "CM";
            tmp %= 900;

            add(tmp / 500, 'D');
            tmp %= 500;
            if (tmp / 400)
                ans += "CD";
            tmp %= 400;

            add(tmp / 100, 'C');
            tmp %= 100;

        case 2:
            if (tmp / 90)
                ans += "XC";
            tmp %= 90;

            add(tmp / 50, 'L');
            tmp %= 50;
            if (tmp / 40)
                ans += "XL";
            tmp %= 40;

            add(tmp / 10, 'X');
            tmp %= 10;

        case 1:
            if (tmp / 9)
                ans += "IX";
            tmp %= 9;

            add(tmp / 5, 'V');
            tmp %= 5;
            if (tmp / 4)
                ans += "IV";
            tmp %= 4;

            add(tmp / 1, 'I');
            break;
        }

        return ans;
    }
};
// @lc code=end
