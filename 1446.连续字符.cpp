/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */

// @lc code=start
class Solution {
  public:
    int maxPower(string s) {
        int n = s.size();
        int ans = 0;
        int cnt = 1;
        char last_char = 0;
        for (auto &i : s) {
            if (i == last_char) {
                ++cnt;
            } else {
                ans = max(ans, cnt);
                cnt = 1;
                last_char = i;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};
// @lc code=end
