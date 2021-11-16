/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
class Solution {
  public:
    int getMoneyAmount(int n) {
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 1; --i) {
            for (int j = i + 1; j <= n; ++j) {
                int minCost = INT_MAX;
                for (int k = i; k < j; ++k) {
                    int cost = k + max(f[i][k - 1], f[k + 1][j]);
                    minCost = min(minCost, cost);
                }
                f[i][j] = minCost;
            }
        }
        return f[1][n];
    }
};
// @lc code=end
