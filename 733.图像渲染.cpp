/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
// #include <bits/stdc++.h>
// using namespace std;

class Solution {
  public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    void dfs(vector<vector<int>> &image, int x, int y, int color,
             int newColor) {
        int n = image.size();
        int m = image[0].size();
        if (image[x][y] == color) {
            image[x][y] = newColor;
            for (int i = 0; i < 4; ++i) {
                int next_x = x + dx[i];
                int next_y = y + dy[i];
                if (next_x >= n || next_x < 0 || next_y >= m || next_y < 0)
                    continue;
                dfs(image, next_x, next_y, color, newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {
        int color = image[sr][sc];
        if (color != newColor)
            dfs(image, sr, sc, color, newColor);
        return image;
    }
};
// @lc code=end
