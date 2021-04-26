/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = 0;
        int i = 0;
        int T = m * n;
        vector<int> ans;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        while (T--) {
            ans.push_back(matrix[x][y]);
            // cout << "i = " << i << " " << matrix[x][y] << endl;
            vis[x][y] = 1;

            x += dir[i][0];
            y += dir[i][1];

            if (y >= n) {
                y = n - 1;
                i = 1;
                x += dir[i][0];
            } else if (x >= m) {
                x = m - 1;
                i = 2;
                y += dir[i][1];
            } else if (y < 0) {
                y = 0;
                i = 3;
                x += dir[i][0];
            } else if (x < 0) {
                x = 0;
                i = 0;
                y += dir[i][1];
            } else {
                if (vis[x][y] == 1) {
                    x -= dir[i][0];
                    y -= dir[i][1];
                    i = (i + 1) % 4;
                    x += dir[i][0];
                    y += dir[i][1];
                }
            }
        }
        return ans;
    }
};
// @lc code=end
