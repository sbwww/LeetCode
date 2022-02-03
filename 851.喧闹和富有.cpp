/*
 * @lc app=leetcode.cn id=851 lang=cpp
 *
 * [851] 喧闹和富有
 */

// @lc code=start
class Solution {
  public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
        int n = quiet.size();
        vector<vector<int>> g(n);
        vector<int> inDeg(n);
        for (auto &r : richer) {
            g[r[0]].emplace_back(r[1]);
            ++inDeg[r[1]];
        }

        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 0);
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (inDeg[i] == 0)
                q.emplace(i);

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : g[x]) {
                if (quiet[ans[x]] < quiet[ans[y]])
                    ans[y] = ans[x]; // 更新 x 的邻居的答案

                if (--inDeg[y] == 0)
                    q.emplace(y);
            }
        }
        return ans;
    }
};
// @lc code=end
