/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */

// @lc code=start
class Solution {
  public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<vector<int>> ans(n, vector<int>());
        ans[0].push_back(nums[0]);
        int max_len = 1;
        int max_ans = 0;

        for (int i = 1; i < n; ++i) {
            int max_index = i;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        max_index = j;
                    }
                }
            }
            ans[i] = ans[max_index];
            ans[i].push_back(nums[i]);
            int tmp_len = dp[i];
            if (max_len < tmp_len) {
                max_ans = i;
                max_len = tmp_len;
            }
        }
        return ans[max_ans];
    }
};
// @lc code=end
