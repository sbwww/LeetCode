/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */

// @lc code=start
class Solution {
  public:
    int maxCount(int m, int n, vector<vector<int>> &ops) {
        int x = m;
        int y = n;
        for (const auto &op : ops) {
            x = min(x, op[0]);
            y = min(y, op[1]);
        }

        return x * y;
    }
};
// @lc code=end
