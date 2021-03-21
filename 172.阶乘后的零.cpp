/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
// 1808548329
class Solution {
  public:
    int trailingZeroes(int n) {
        unsigned long long tmp = 5;
        int ans = 0;
        while (tmp <= n) {
            ans += n / tmp;
            tmp *= 5;
        }
        return ans;
    }
};
// @lc code=end
