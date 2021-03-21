/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
  public:
    int climbStairs(int n) {
        int ans = 0;
        int tmp1 = 0, tmp2 = 1;
        for (int i = 0; i < n; ++i) {
            ans = tmp1 + tmp2;
            tmp1 = tmp2;
            tmp2 = ans;
        }
        return ans;
    }
};
// @lc code=end
