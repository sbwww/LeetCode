/*
 * @lc app=leetcode.cn id=1723 lang=cpp
 *
 * [1723] 完成所有工作的最短时间
 */

// @lc code=start
class Solution {
  public:
    int minimumTimeRequired(vector<int> &jobs, int k) {
        int n = jobs.size();
        int len = 1 << n;
        vector<int> sum(len);
        for (int i = 1; i < len; ++i) {
            int x = __builtin_ctz(i); // 末尾的 0
            int y = i - (1 << x);
            sum[i] = sum[y] + jobs[x];
        }

        vector<vector<int>> dp(k, vector<int>(len));
        for (int i = 0; i < len; ++i)
            dp[0][i] = sum[i];

        for (int i = 1; i < k; ++i) {
            for (int j = 0; j < len; ++j) {
                int minn = INT_MAX;
                for (int x = j; x; x = (x - 1) & j) { // 子集
                    minn = min(minn, max(dp[i - 1][j - x], sum[x]));
                }
                dp[i][j] = minn;
            }
        }
        return dp[k - 1][len - 1];
    }
};
// @lc code=end
