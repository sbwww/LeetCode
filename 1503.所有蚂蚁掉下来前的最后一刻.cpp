/*
 * @lc app=leetcode.cn id=1503 lang=cpp
 *
 * [1503] 所有蚂蚁掉下来前的最后一刻
 */

// @lc code=start
class Solution {
  public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right) {
        int ans = -1;
        for (auto num : left)
            ans = max(ans, num);
        for (auto num : right)
            ans = max(ans, n - num);
        return ans;
    }
};
// @lc code=end
