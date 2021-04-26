/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int min_in_first_i = 1e5 + 1;
        int ans = 0;
        for (auto p : prices) {
            min_in_first_i = min(min_in_first_i, p);
            ans = max(ans, p - min_in_first_i);
        }
        return ans;
    }
};
// @lc code=end
