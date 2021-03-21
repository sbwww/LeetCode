/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int tmpSum = nums[0];
        int maxSum = tmpSum;
        for (int i = 1; i < nums.size(); ++i) {
            tmpSum += nums[i];
            tmpSum = max(nums[i], tmpSum);
            maxSum = max(maxSum, tmpSum);
        }
        return maxSum;
    }
};
// @lc code=end
