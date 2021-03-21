/*
 * @lc app=leetcode.cn id=999 lang=cpp
 *
 * [999] 可以被一步捕获的棋子数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    const int MAX_ROW = 8;
    const int MAX_COL = 8;
    int numRookCaptures(vector<vector<char>> &board) {
        int posX, posY, cnt = 0;
        for (int i = 0; i < MAX_ROW; ++i) {
            for (int j = 0; j < MAX_COL; ++j) {
                if (board[i][j] == 'R') {
                    posX = i;
                    posY = j;
                }
            }
        }
        for (int i = posX - 1; i >= 0; --i) {
            int j = posY;
            if (board[i][j] == 'B') {
                break;
            } else if (board[i][j] == 'p') {
                ++cnt;
                break;
            }
        }
        for (int i = posX + 1; i < 8; ++i) {
            int j = posY;
            if (board[i][j] == 'B') {
                break;
            } else if (board[i][j] == 'p') {
                ++cnt;
                break;
            }
        }
        for (int j = posY - 1; j >= 0; --j) {
            int i = posX;
            if (board[i][j] == 'B') {
                break;
            } else if (board[i][j] == 'p') {
                ++cnt;
                break;
            }
        }
        for (int j = posY + 1; j < 8; ++j) {
            int i = posX;
            if (board[i][j] == 'B') {
                break;
            } else if (board[i][j] == 'p') {
                ++cnt;
                break;
            }
        }
        return cnt;
    }
};
// @lc code=end
