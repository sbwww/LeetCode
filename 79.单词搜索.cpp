/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
  public:
    int m, n;
    string word;
    vector<vector<bool>> vis;
    bool dfs(vector<vector<char>> &board, int x, int y, int pos) {
        if (pos >= word.length())
            return true;
        if (x < 0 || x >= m || y < 0 || y >= n)
            return false;
        if (vis[x][y])
            return false;
        if (board[x][y] != word[pos])
            return false;
        vis[x][y] = true;
        if (dfs(board, x, y + 1, pos + 1) || dfs(board, x + 1, y, pos + 1) ||
            dfs(board, x, y - 1, pos + 1) || dfs(board, x - 1, y, pos + 1)) {
            vis[x][y] = false;
            return true;
        }
        vis[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word) {
        this->m = board.size();
        this->n = board[0].size();
        this->word = word;
        this->vis = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end
