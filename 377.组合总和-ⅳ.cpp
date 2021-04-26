/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
  public:
    using ull = unsigned long long;
    int combinationSum4(vector<int> &nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<ull> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; ++i) {
            for (auto val : nums) {
                if (val > i)
                    break;
                dp[i] += dp[i - val];
            }
        }

        return dp[target];
    }
};
// @lc code=end
