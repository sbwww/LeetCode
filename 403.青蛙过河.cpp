/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */

// @lc code=start
class Solution {
  public:
    bool canCross(vector<int> &stones) {
        int n = stones.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        dp[0][0] = true;

        for (int i = 1; i < n; ++i) {
            if (stones[i] - stones[i - 1] > i)
                return false;

            for (int j = i - 1; j >= 0; --j) {
                int k = stones[i] - stones[j];
                if (k > j + 1)
                    break;

                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                if (i == n - 1 && dp[i][k])
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
