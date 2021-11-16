/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */

// @lc code=start
typedef pair<int, int> pii;

class Solution {
  public:
    int trapRainWater(vector<vector<int>> &heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (heightMap.size() <= 2 || heightMap[0].size() <= 2)
            return 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<vector<bool>> visit(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], i * n + j});
                    visit[i][j] = true;
                }
            }
        }

        int res = 0;
        int dirs[] = {-1, 0, 1, 0, -1}; // 4 directions, the last one equal to the first one, for k+1 below

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            for (int k = 0; k < 4; ++k) {
                int nx = curr.second / n + dirs[k];
                int ny = curr.second % n + dirs[k + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny]) {
                    if (heightMap[nx][ny] < curr.first) {
                        res += curr.first - heightMap[nx][ny];
                    }
                    visit[nx][ny] = true;
                    pq.push(make_pair(max(heightMap[nx][ny], curr.first),
                                      nx * n + ny));
                }
            }
        }

        return res;
    }
};
// @lc code=end
