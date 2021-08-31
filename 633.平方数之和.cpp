/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
  public:
    bool isSquare(int n) {
        if (n == 0)
            return true;
        int i = sqrt(n);
        return i * i == n;
    }
    bool judgeSquareSum(int c) {
        if (c == 0)
            return true;
        int len = sqrt(c);
        for (int i = 1; i <= len; ++i) {
            if (isSquare(c - i * i)) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
