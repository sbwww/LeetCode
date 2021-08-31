/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
    vector<int> tmp;

  public:
    void dfs(vector<vector<int>> &graph, int cur, int dst) {
        if (cur == dst) {
            ans.emplace_back(tmp);
            return;
        }
        for (auto &next : graph[cur]) {
            tmp.emplace_back(next);
            dfs(graph, next, dst);
            tmp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        tmp.emplace_back(0);
        int n = graph.size();
        dfs(graph, 0, n - 1);
        return ans;
    }
};
// @lc code=end
