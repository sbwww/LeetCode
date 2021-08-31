/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start

// class Solution {
//     vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

//   public:
//     vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
//         queue<pair<int, int>> q;
//         int m = mat.size();
//         int n = mat[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         vector<vector<int>> vis(m, vector<int>(n, 0));
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (!mat[i][j]) {
//                     q.emplace(i, j);
//                     vis[i][j] = 1;
//                 }
//             }
//         }

//         while (!q.empty()) {
//             auto item = q.front();
//             int i = item.first;
//             int j = item.second;
//             q.pop();
//             for (auto d : directions) {
//                 int ti = i + d[0];
//                 int tj = j + d[1];
//                 if (ti >= 0 && ti < m && tj >= 0 && tj < n &&
//                     vis[ti][tj] == 0) {
//                     dp[ti][tj] = dp[i][j] + 1;
//                     q.emplace(ti, tj);
//                     vis[ti][tj] = 1;
//                 }
//             }
//         }

//         return dp;
//     }
// };

class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 初始化动态规划的数组，所有的距离值都设置为一个很大的数
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX / 2));
        // 如果 (i, j) 的元素为 0，那么距离为 0
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == 0)
                    dp[i][j] = 0;

        // 只有 水平向左移动 和 竖直向上移动，注意动态规划的计算顺序
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - 1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                if (j - 1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
        // 只有 水平向右移动 和 竖直向下移动，注意动态规划的计算顺序
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i + 1 < m)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                if (j + 1 < n)
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            }
        }

        return dp;
    }
};
// @lc code=end
