/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int dp[201] = {triangle[0][0]};
        int ans = 1e4 + 1;
        for (int i = 1; i < triangle.size(); ++i) { // 行数
            int tail = triangle[i].size() - 1;
            dp[tail] = dp[tail - 1] + triangle[i][tail];
            for (int j = tail - 1; j >= 1; --j) { // 列数
                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }
        for (int j = 0; j < triangle.size(); ++j)
            ans = min(ans, dp[j]);
        return ans;
    }
};
// @lc code=end
