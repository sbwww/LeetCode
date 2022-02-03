/*
 * @lc app=leetcode.cn id=1342 lang=cpp
 *
 * [1342] 将数字变成 0 的操作次数
 */

// @lc code=start
class Solution {
  public:
    int numberOfSteps(int num) {
        return num ? 31 - __builtin_clz(num) + __builtin_popcount(num) : 0;
    }
};
// @lc code=end
