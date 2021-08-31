/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */

// @lc code=start
class Solution {
  public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int k) {
        queue<pair<int, int>> Q;
        Q.push(make_pair(src, 0));

        vector<int> dis(n, INT_MAX);
        dis[src] = 0;

        unordered_map<int, unordered_map<int, int>> graph;
        for (auto &flight : flights)
            graph[flight[0]][flight[1]] = flight[2];

        int step = 0;
        int ans = -1;

        while (!Q.empty() && step <= k + 1) {
            int size = Q.size();
            while (size) {
                auto [node, distance] = Q.front();

                Q.pop();
                --size;

                if (node == dst && (ans == -1 || ans > distance)) {
                    ans = distance;
                    continue;
                }

                for (auto &[next, weight] : graph[node]) {
                    if (distance + weight < dis[next]) {
                        dis[next] = min(dis[next], distance + weight);
                        Q.push(make_pair(next, distance + weight));
                    }
                }
            }

            ++step;
        }

        return ans;
    }
};
// @lc code=end
