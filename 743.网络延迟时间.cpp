/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
class Solution {
    vector<int> vis;
    queue<int> q;

  public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        vis = vector<int>(n + 1, -1);
        vis[k] = 0;
        q.push(k);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &row : times) {
                if (row[0] == cur) {
                    if (vis[row[1]] == -1 ||
                        vis[row[1]] > vis[row[0]] + row[2]) {
                        vis[row[1]] = vis[row[0]] + row[2];
                        q.push(row[1]);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (vis[i] == -1)
                return -1;
            ans = max(ans, vis[i]);
        }
        return ans;
    }
};
// @lc code=end
