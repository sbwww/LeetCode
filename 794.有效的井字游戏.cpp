/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 */

// @lc code=start
class Solution {
  public:
    bool validTicTacToe(vector<string> &board) {
        int cnt_X = 0;
        int cnt_O = 0;
        int cnt_win1 = 0;
        int cnt_win2 = 0;
        for (auto &s : board) {
            if (s == "XXX")
                ++cnt_win1;
            else if (s == "OOO")
                ++cnt_win2;
            for (auto &c : s) {
                if (c == 'X')
                    ++cnt_X;
                else if (c == 'O')
                    ++cnt_O;
            }
        }
        if (cnt_X < cnt_O)
            return false;
        if (cnt_X - cnt_O > 1)
            return false;
        if (cnt_win1 + cnt_win2 > 1)
            return false;

        if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
            ++cnt_win1;
        if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
            ++cnt_win1;
        if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
            ++cnt_win1;
        if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
            ++cnt_win1;
        if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
            ++cnt_win1;

        if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
            ++cnt_win2;
        if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
            ++cnt_win2;
        if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
            ++cnt_win2;
        if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
            ++cnt_win2;
        if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
            ++cnt_win2;

        if (cnt_win1 == 2 && cnt_win2 == 0 && cnt_X == 5)
            return true;
        if (cnt_win1 == 1 && cnt_X == cnt_O)
            return false;
        if (cnt_win1 + cnt_win2 > 1)
            return false;
        if (cnt_win2 == 1 && cnt_X > cnt_O)
            return false;
        return true;
    }
};
// @lc code=end
