/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
  public:
    int integerBreak(int n) {
        if (n <= 3)
            return n - 1;

        int q = n / 3;
        int r = n % 3;
        if (r == 0)
            return (int)pow(3, q);
        else if (r == 1)
            return (int)pow(3, q - 1) * 4;
        else
            return (int)pow(3, q) * 2;
    }
};
// @lc code=end
