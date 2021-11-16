/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
  public:
    bool isPerfectSquare(int num) {
        double eps = 1e-10;
        double x0 = num;
        while (true) {
            double x1 = (x0 + num / x0) / 2;
            if (x0 - x1 < eps)
                break;

            x0 = x1;
        }
        int x = (int)x0;
        return x * x == num;
    }
};
// @lc code=end
