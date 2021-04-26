/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
// #include <bits/stdc++.h>
// using namespace std;

class Solution {
  public:
    int row, col;
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        row = matrix.size();
        col = matrix[0].size();
        int left = 0;
        int right = row * col - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int mid_val = matrix[mid / col][mid % col];
            if (mid_val == target)
                return true;
            if (mid_val > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};
// @lc code=end
