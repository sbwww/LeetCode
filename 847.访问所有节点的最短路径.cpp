/*
 * @lc app=leetcode.cn id=847 lang=cpp
 *
 * [847] 访问所有节点的最短路径
 */

// @lc code=start
class Solution {
    int INF = 0x3f3f3f3f;

  public:
    int shortestPathLength(vector<vector<int>> &graph) {
        int n = graph.size();
        int mask = 1 << n;

        // 初始化所有的 (state, u) 距离为正无穷
        vector<vector<int>> dist(mask, vector<int>(n, INF));

        // 因为可以从任意起点出发，先将起始的起点状态入队，并设起点距离为 0
        deque<vector<int>> d; // state, u

        for (int i = 0; i < n; ++i) {
            dist[1 << i][i] = 0;
            d.emplace_back(vector<int>{1 << i, i});
        }

        // BFS 过程，如果从点 u 能够到达点 i，则更新距离并进行入队
        while (!d.empty()) {
            vector<int> poll = d.front();
            d.pop_front();
            int state = poll[0], u = poll[1], step = dist[state][u];
            if (state == mask - 1)
                return step;
            for (int &i : graph[u]) {
                if (dist[state | (1 << i)][i] == INF) {
                    dist[state | (1 << i)][i] = step + 1;
                    d.emplace_back(vector<int>{state | (1 << i), i});
                }
            }
        }
        return -1; // never
    }
};
// @lc code=end
