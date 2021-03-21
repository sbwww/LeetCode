/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// MCMXCIV
class Solution {
  public:
    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;
        map<char, int> val;
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
        for (int i = 0; i < n; ++i) {
            if ((s[i] == 'I' && (s[i + 1] == 'V' || (s[i + 1] == 'X'))) ||
                (s[i] == 'X' && (s[i + 1] == 'L' || (s[i + 1] == 'C'))) ||
                (s[i] == 'C' && (s[i + 1] == 'D' || (s[i + 1] == 'M')))) {
                ans += val[s[i + 1]] - val[s[i]];
                ++i;
            } else {
                ans += val[s[i]];
            }
        }
        return ans;
    }
};
// @lc code=end
