/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

// 1 3 6 7 9 4 10 5 6

class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;

        int dp[2501] = {1};
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int ans = 1;
        for (int i = 0; i < nums.size(); ++i) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end
