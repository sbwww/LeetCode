/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

// @lc code=start
class Solution {
  public:
    int integerReplacement(int n) {
        int ans = 0;
        while (n != 1) {
            if ((n & 1) == 0) { // 偶数直接除
                ++ans;
                n >>= 1;
            } else if (n % 4 == 1) { // 4n+1 减1除2
                ans += 2;
                n >>= 1;
            } else {
                if (n == 3) {
                    ans += 2;
                    n = 1;
                } else {
                    ans += 2;
                    n = (n >> 1) + 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
