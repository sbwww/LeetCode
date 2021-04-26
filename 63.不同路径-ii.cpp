/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        vector<int> dp(n, 0);
        for (int j = 0; j < n; ++j) {
            int flag = 1 - obstacleGrid[0][j];
            dp[j] = flag;
            if (flag == 0)
                break;
        }
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 1)
                dp[0] = 0;
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else
                    dp[j] = dp[j - 1] * (1 - obstacleGrid[i][j - 1]) +
                            dp[j] * (1 - obstacleGrid[i - 1][j]);
            }
        }
        return dp[n - 1];
    }
};
/*
[[0,0],[1,1],[0,0]]
*/
// @lc code=end
