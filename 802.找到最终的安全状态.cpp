/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * [802] 找到最终的安全状态
 */

// @lc code=start
class Solution {
    vector<int> color;

  public:
    bool safe(int x, vector<vector<int>> &graph) {
        if (color[x] > 0)
            return color[x] == 2;

        color[x] = 1;
        for (int y : graph[x])
            if (!safe(y, graph))
                return false;

        color[x] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = graph.size();
        color = vector<int>(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; ++i)
            if (safe(i, graph))
                ans.emplace_back(i);

        return ans;
    }
};
// @lc code=end
