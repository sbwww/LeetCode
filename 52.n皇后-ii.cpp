/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
  public:
    int totalNQueens(int n) { return solve(n, 0, 0, 0, 0); }

    int solve(int n, int row, int columns, int diagonals1, int diagonals2) {
        if (row == n) {
            return 1;
        } else {
            int count = 0;
            // 可以放皇后的位置，availablePositions 中为 1 的位可以放皇后
            int availablePositions =
                ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions != 0) {
                // x & (−x) -> x 最低位的 1 的位置
                // x & (x−1) -> x 最低位的 1 置成 0
                int position = availablePositions & (-availablePositions);
                availablePositions &= (availablePositions - 1);
                count += solve(n, row + 1, columns | position,
                               (diagonals1 | position) << 1,
                               (diagonals2 | position) >> 1);
            }
            return count;
        }
    }
};
// @lc code=end
