/*
 * @lc app=leetcode.cn id=576 lang=cpp
 *
 * [576] 出界的路径数
 */

// @lc code=start
class Solution {
  public:
    const int MOD = 1e9 + 7;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> dp(m, vector<int>(n));
        dp[startRow][startColumn] = 1;
        int ans = 0;

        for (int i = 0; i < maxMove; ++i) {
            vector<vector<int>> dp_next(m, vector<int>(n));
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    int count = dp[j][k];
                    if (count > 0) {
                        for (auto &dir : directions) {
                            int j1 = j + dir[0];
                            int k1 = k + dir[1];
                            if (j1 >= 0 && j1 < m && k1 >= 0 && k1 < n)
                                dp_next[j1][k1] = (dp_next[j1][k1] + count) % MOD;
                            else
                                ans = (ans + count) % MOD;
                        }
                    }
                }
            }
            dp = dp_next;
        }
        return ans;
    }
};
// @lc code=end
