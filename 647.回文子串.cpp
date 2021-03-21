/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
  public:
    const int MAXN = 1005;
    int countSubstrings(string s) {
        int n = s.length();
        bool dp[MAXN][MAXN] = {0};
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            for (int j = i; j < n; ++j) {
                if (s[i - 1] == s[j]) {
                    dp[i - 1][j + 1] = dp[i][j] + 1;
                }
            }
        }
    }
};
// @lc code=end
