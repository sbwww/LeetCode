/*
 * @lc app=leetcode.cn id=1716 lang=cpp
 *
 * [1716] 计算力扣银行的钱
 */

// @lc code=start
class Solution {
  public:
    int totalMoney(int n) {
        int week = n / 7;
        int day = n % 7;
        int ans = (1 + day) * day / 2 + day * week;
        if (week > 0)
            ans += (4 + 4 + week - 1) * week / 2 * 7;
        return ans;
    }
};
// @lc code=end
