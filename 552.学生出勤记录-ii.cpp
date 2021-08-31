/*
 * @lc app=leetcode.cn id=552 lang=cpp
 *
 * [552] 学生出勤记录 II
 */

// @lc code=start
class Solution {
  public:
    int MOD = 1e9 + 7;

    int checkRecord(int n) {
        vector<vector<int>> dp(2, vector<int>(3, 0));
        // int dp[2][3];
        // memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            vector<vector<int>> dpNew(2, vector<int>(3, 0));
            // int dpNew[2][3];
            // memset(dpNew, 0, sizeof(dpNew));
            // 以 P 结尾的数量
            for (int j = 0; j <= 1; ++j)
                for (int k = 0; k <= 2; ++k)
                    dpNew[j][0] = (dpNew[j][0] + dp[j][k]) % MOD;

            // 以 A 结尾的数量
            for (int k = 0; k <= 2; ++k)
                dpNew[1][0] = (dpNew[1][0] + dp[0][k]) % MOD;

            // 以 L 结尾的数量
            for (int j = 0; j <= 1; ++j)
                for (int k = 1; k <= 2; ++k)
                    dpNew[j][k] = (dpNew[j][k] + dp[j][k - 1]) % MOD;

            dp = dpNew;
            // memcpy(dp, dpNew, sizeof(dp));
        }

        int sum = 0;
        for (int j = 0; j <= 1; ++j)
            for (int k = 0; k <= 2; ++k)
                sum = (sum + dp[j][k]) % MOD;

        return sum;
    }
};
// @lc code=end
