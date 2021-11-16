/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
  public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        int ans = 0;
        int cur = 0;
        for (auto &i : timeSeries) {
            ans += duration + min(0, i - cur);
            cur = i + duration;
        }
        return ans;
    }
};
// @lc code=end
