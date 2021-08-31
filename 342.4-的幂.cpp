/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
  public:
    bool isPowerOfTwo(int n) { return (n & (n - 1)) == 0; }
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        int sqrtn = sqrt(n);
        if (sqrtn * sqrtn < n)
            return false;
        return isPowerOfTwo(n) && isPowerOfTwo(sqrtn);
    }
};
// @lc code=end
