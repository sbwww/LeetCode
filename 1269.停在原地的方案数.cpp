/*
 * @lc app=leetcode.cn id=1269 lang=cpp
 *
 * [1269] 停在原地的方案数
 */

// @lc code=start
class Solution {
    int MOD = 1e9 + 7;

  public:
    int numWays(int steps, int arrLen) {
        // int maxLen = min(arrLen - 1, steps);
        int maxLen = min(arrLen - 1, steps / 2);
        vector<int> dp(maxLen + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < steps; ++i) {
            vector<int> tmp = dp;
            // vector<int> tmp(maxLen + 1, 0);
            for (int j = 0; j <= maxLen; ++j) {
                // tmp[j] = dp[j];
                if (j - 1 >= 0)
                    tmp[j] = (tmp[j] + dp[j - 1]) % MOD;
                if (j + 1 <= maxLen)
                    tmp[j] = (tmp[j] + dp[j + 1]) % MOD;
            }
            dp = tmp;
        }
        return dp[0];
    }
};
// @lc code=end
