/*
 * @lc app=leetcode.cn id=1824 lang=cpp
 *
 * [1824] 最少侧跳次数
 */

// @lc code=start
class Solution {
  public:
    int minSideJumps(vector<int> &obstacles) {
        int MAXN = 5e5 + 5;
        int n = obstacles.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][1] = 1;
        dp[0][2] = 0;
        dp[0][3] = 1;
        for (int i = 1; i < n; ++i) {
            int tmp = obstacles[i];
            int tmp_last = obstacles[i - 1];
            if (tmp == 0) {
                dp[i][1] =
                    min(dp[i - 1][1], min(dp[i - 1][2], dp[i - 1][3]) + 1);
                dp[i][2] =
                    min(dp[i - 1][2], min(dp[i - 1][3], dp[i - 1][1]) + 1);
                dp[i][3] =
                    min(dp[i - 1][3], min(dp[i - 1][1], dp[i - 1][2]) + 1);
            }
            if (tmp == 1) {
                dp[i][1] = MAXN;
                dp[i][2] = min(dp[i - 1][2], dp[i - 1][3] + 1);
                dp[i][3] = min(dp[i - 1][3], dp[i - 1][2] + 1);
            }
            if (tmp == 2) {
                dp[i][2] = MAXN;
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][3] + 1);
                dp[i][3] = min(dp[i - 1][3], dp[i - 1][1] + 1);
            }
            if (tmp == 3) {
                dp[i][3] = MAXN;
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][2] + 1);
                dp[i][2] = min(dp[i - 1][2], dp[i - 1][1] + 1);
            }
        }
        return min(min(dp[n - 1][1], dp[n - 1][2]), dp[n - 1][3]);
    }
};
// [0,1,0,1,3,1,1,1,0,2,0]
// 1
// @lc code=end
