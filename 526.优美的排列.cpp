/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 */

// @lc code=start
class Solution {
  public:
    int countArrangement(int n) {
        int stat_cnt = 1 << n;
        vector<int> dp(stat_cnt);
        dp[0] = 1;
        for (int mask = 1; mask < stat_cnt; ++mask) {
            int num = __builtin_popcount(mask);
            for (int i = 0; i < n; ++i) {
                int chose_bit = 1 << i;
                if (mask & chose_bit &&
                    (num % (i + 1) == 0 || (i + 1) % num == 0)) {
                    dp[mask] += dp[mask ^ chose_bit];
                }
            }
        }
        return dp[stat_cnt - 1];
    }
};
// @lc code=end
