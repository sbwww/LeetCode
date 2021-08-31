/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ans = ans ^ i ^ nums[i];
        }
        return ans;
    }
};
// @lc code=end
