/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> days;
        int n = temperatures.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!days.empty() && temperatures[days.top()] <= temperatures[i]) {
                days.pop();
            }
            ans[i] = days.empty() ? 0 : days.top() - i;
            days.push(i);
        }

        return ans;
    }
};
// @lc code=end
