/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution {
  public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = nums.size();
        if (n < 3)
            return 0;

        int diff = nums[0] - nums[1];
        int tmp_len = 2;
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] - nums[i + 1] == diff) {
                ++tmp_len;
            } else {
                if (tmp_len >= 3) {
                    ans += (1 + tmp_len - 3 + 1) * (tmp_len - 3 + 1) / 2;
                }
                tmp_len = 2;
                diff = nums[i] - nums[i + 1];
            }
        }
        if (tmp_len >= 3) {
            ans += (1 + tmp_len - 3 + 1) * (tmp_len - 3 + 1) / 2;
        }

        return ans;
    }
};
// @lc code=end
