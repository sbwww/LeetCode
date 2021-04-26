/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
  public:
    int C(int n, int m) { // C_n^m
        int tmp = n - m;
        m = tmp < m ? tmp : m;
        unsigned long long ans = 1;
        for (int i = 0; i < m; ++i) {
            ans = ans * (unsigned long long)(n - i) / (unsigned long long)(i + 1);
        }
        return (int)ans;
    }
    int uniquePaths(int m, int n) {
        // vector<int> dp(n, 1);
        // for (int i = 1; i < m; ++i) {
        //     for (int j = 1; j < n; ++j) {
        //         dp[j] = dp[j - 1] + dp[j];
        //     }
        // }
        // return dp[n - 1];
        return C(n + m - 2, n - 1);
    }
};
// @lc code=end
