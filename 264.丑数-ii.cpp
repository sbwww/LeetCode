/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
  public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            int num2 = dp[p2] * 2;
            int num3 = dp[p3] * 3;
            int num5 = dp[p5] * 5;
            dp[i] = min(min(num2, num3), num5);
            if (dp[i] == num2)
                ++p2;
            if (dp[i] == num3)
                ++p3;
            if (dp[i] == num5)
                ++p5;
        }
        return dp[n - 1];
    }
};
// @lc code=end
