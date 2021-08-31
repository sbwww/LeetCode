/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution {
  public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
        vector<int> diff(n + 1, 0);
        for (auto &info : bookings) {
            diff[info[0] - 1] += info[2];
            diff[info[1]] -= info[2];
        }
        int sum = 0;
        for (auto &i : diff) {
            sum += i;
            i = sum;
        }
        diff.pop_back();
        return diff;
    }
};
// @lc code=end
