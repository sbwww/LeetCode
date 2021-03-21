/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";

        int MAXN = strs[0].length();
        int flag = 1;
        int i;
        for (i = 0; i < MAXN; ++i) {
            char tmp = strs[0][i];
            // cout << tmp << endl;
            for (auto s : strs) {
                if (s[i] != tmp) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
                break;
        }
        // cout << i << endl;
        return strs[0].substr(0, i);
    }
};
// @lc code=end
