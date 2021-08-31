/*
 * @lc app=leetcode.cn id=1473 lang=cpp
 *
 * [1473] 粉刷房子 III
 */

// @lc code=start
class Solution {
  private:
    // 防止整数相加溢出，魔法
    static constexpr int MAXN = INT_MAX / 2;

  public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n,
                int target) {
        // 三维dp数组 m*(n+1)*target
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n + 1, vector<int>(target, MAXN)));

        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (houses[i] != 0 && houses[i] != j)
                    continue;

                for (int k = 0; k < target; ++k) {
                    for (int j0 = 1; j0 <= n; ++j0) {
                        if (j == j0) {
                            if (i == 0) {
                                if (k == 0) {
                                    dp[i][j][k] = 0;
                                }
                            } else {
                                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                            }
                        } else if (i > 0 && k > 0) {
                            dp[i][j][k] =
                                min(dp[i][j][k], dp[i - 1][j0][k - 1]);
                        }
                    }

                    if (dp[i][j][k] != MAXN && houses[i] == 0)
                        dp[i][j][k] += cost[i][j - 1];
                }
            }
        }

        int ans = MAXN;
        for (int j = 1; j <= n; ++j)
            ans = min(ans, dp[m - 1][j][target - 1]);

        return ans == MAXN ? -1 : ans;
    }
};
// @lc code=end
