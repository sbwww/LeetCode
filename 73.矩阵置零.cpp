/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int m, n;
    void setZeroes(vector<vector<int>> &matrix) {
        m = matrix.size();
        n = matrix[0].size();
        bool isZeroCol = false;
        bool isZeroRow = false;
        for (int i = 0; i < m; ++i)
            if (matrix[i][0] == 0)
                isZeroCol = true;
        for (int j = 0; j < n; ++j)
            if (matrix[0][j] == 0)
                isZeroRow = true;

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][j] == 0)
                    matrix[i][0] = 0, matrix[0][j] = 0;

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        if (isZeroCol)
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        if (isZeroRow)
            for (int j = 0; j < n; ++j)
                matrix[0][j] = 0;
    }
};
// [ [ 0, 1, 2, 0 ], [ 3, 4, 5, 2 ], [ 1, 3, 1, 5 ] ]
// @lc code=end
