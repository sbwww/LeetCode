/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
  public:
    int countDigitOne(int n) {
        if (n <= 0)
            return 0;

        long long weight = 1;
        int ans = 0;

        for (int i = 0; weight <= n; ++i) {
            ans += (n / (weight * 10)) * weight +
                   min(max(n % (weight * 10) - weight + 1, 0LL), weight);
            weight *= 10;
        }
        return ans;
    }
};
// @lc code=end
