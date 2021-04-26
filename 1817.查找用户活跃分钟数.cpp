/*
 * @lc app=leetcode.cn id=1817 lang=cpp
 *
 * [1817] 查找用户活跃分钟数
 */

// @lc code=start
class Solution {
  public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
        map<int, set<int>> m;
        vector<int> ans(k);
        for (auto log : logs) {
            m[log[0]].insert(log[1]);
        }
        for (auto user : m) {
            ++ans[user.second.size() - 1];
        }
        return ans;
    }
};
// @lc code=end
