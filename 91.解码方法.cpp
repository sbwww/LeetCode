/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
  public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        int dp_last = 1, dp = 1; // dp[-1] = dp[0] = 1
        int len = s.size();
        for (int i = 1; i < len; ++i) {
            int tmp = dp;
            if (s[i] == '0')
                if (s[i - 1] == '1' || s[i - 1] == '2')
                    dp = dp_last;
                else
                    return 0;
            else if ((s[i - 1] == '1') ||
                     (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
                dp = dp + dp_last;
            dp_last = tmp;
        }
        return dp;
    }
};
// @lc code=end
