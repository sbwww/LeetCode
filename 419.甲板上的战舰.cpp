/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
class Solution {
    using ULL = unsigned long long;

  public:
    int countBattleships(vector<vector<char>> &board) {
        int m = board.size();
        int n = board[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j > 0 && board[i][j - 1] == 'X')
                    continue;
                if (i > 0 && board[i - 1][j] == 'X')
                    continue;
                if (board[i][j] == 'X')
                    ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end
