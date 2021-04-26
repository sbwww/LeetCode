/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        int len_coins = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            int min_cnt = dp[i];
            for (int j = 0; j < len_coins; ++j) {
                if (coins[j] <= i)
                    min_cnt = min(min_cnt, dp[i - coins[j]]);
            }
            dp[i] = min_cnt + 1;
        }
        int ans = dp[amount];
        if (ans > amount)
            return -1;
        return ans;
    }
};
// @lc code=end
