/*
 * @lc app=leetcode.cn id=789 lang=cpp
 *
 * [789] 逃脱阻碍者
 */

// @lc code=start
class Solution {
  public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
        int my_dis = abs(target[0]) + abs(target[1]);
        for (auto &ghost : ghosts) {
            if (abs(target[0] - ghost[0]) + abs(target[1] - ghost[1]) <= my_dis)
                return false;
        }
        return true;
    }
};
// @lc code=end
