/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[1001][1001] = {0}; // i 到 j 是不是回文， 0-1 变量
        string ans;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l; // 尾
                if (l == 0)    // 长度为 1
                    dp[i][j] = 1;
                else if (l == 1) // 长度为 2
                    dp[i][j] = (s[i] == s[j]);
                else { // 两头是否相等，中间是否回文
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && (l + 1 > ans.size())) // 回文 且 比目前的 ans 长
                    ans = s.substr(i, l + 1);
            }
        }
        return ans;
    }
};
// @lc code=end
