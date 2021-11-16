/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
  public:
    double myPow(double x, int n) {
        double ans = 1;
        long long base = n;
        if (base < 0) {
            base = -base;
            x = 1.0 / x;
        }
        while (base) {
            if (base & 1)
                ans *= x;
            x *= x;
            base >>= 1;
        }
        return ans;
    }
};
// @lc code=end
