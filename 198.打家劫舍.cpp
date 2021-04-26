/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
  public:
    // int rob(vector<int> &nums) {
    //     int n = nums.size();
    //     if (n == 0)
    //         return 0;
    //     if (n == 1)
    //         return nums[0];
    //     vector<int> dp(n, 0); // 偷第 i 个能拿到的最大
    //     dp[0] = nums[0];
    //     dp[1] = max(nums[0], nums[1]);
    //     if (n == 2)
    //         return dp[1];
    //     for (int i = 2; i < n; ++i) {
    //         dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    //     }
    //     return max(dp[n - 1], dp[n - 2]);
    // }

    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        int tmp = 0;
        int last_1 = max(nums[0], nums[1]);
        int last_2 = nums[0];
        for (int i = 2; i < n; ++i) {
            tmp = last_1;
            last_1 = max(last_1, last_2 + nums[i]);
            last_2 = tmp;
        }
        return max(last_1, last_2);
    }
};
// @lc code=end
