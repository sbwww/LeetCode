/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
  public:
    int findComplement(int num) {
        double eps = 1e-10;
        int n = ceil(log2(num) + eps);
        int mask = (1 << n) - 1;
        return num ^ mask;
    }
};
// @lc code=end
