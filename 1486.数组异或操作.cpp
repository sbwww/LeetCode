/*
 * @lc app=leetcode.cn id=1486 lang=cpp
 *
 * [1486] 数组异或操作
 */

// @lc code=start
class Solution {
  public:
    int sumXor(int x) {
        switch (x % 4) {
        case 0:
            return x;
        case 1:
            return 1;
        case 2:
            return x + 1;
        case 3:
            return 0;
        default:
            return 0;
        }
    }
    int xorOperation(int n, int start) {
        int s = start >> 1;
        int e = n & start & 1;
        return (sumXor(s - 1) ^ sumXor(s + n - 1)) << 1 | e;
    }
};
// @lc code=end
