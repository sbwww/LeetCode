/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    const int MAXN = 1001;
    vector<vector<int>> ans;
    void one_round(int level, int n, int k) {
        if (level > (n + 1) / 2)
            return;
        for (int i = level - 1; i <= n - level; ++i)
            ans[level - 1][i] = k++;
        for (int i = level; i <= n - level - 1; ++i)
            ans[i][n - level] = k++;
        for (int i = n - level; i >= level - 1 + 1; --i)
            ans[n - level][i] = k++;
        for (int i = n - level; i >= level - 1 + 1; --i)
            ans[i][level - 1] = k++;

        one_round(level + 1, n, k);
    }
    vector<vector<int>> generateMatrix(int n) {
        ans = vector<vector<int>>(n, vector<int>(n));
        one_round(1, n, 1);
        return ans;
    }
};
// @lc code=end
