/*
 * @lc app=leetcode.cn id=1518 lang=cpp
 *
 * [1518] 换酒问题
 */

// @lc code=start
class Solution {
  public:
    int numWaterBottles(int numBottles, int numExchange) {
        int n = numBottles;
        int ans = n;
        while (n >= numExchange) {
            ans += n / numExchange;
            n = n / numExchange + n % numExchange;
        }
        return ans;
    }
};
// @lc code=end
