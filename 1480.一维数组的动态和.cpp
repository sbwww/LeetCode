/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
class Solution {
  public:
    vector<int> runningSum(vector<int> &nums) {
        int sum = 0;
        for (auto &i : nums) {
            i += sum;
            sum = i;
        }
        return nums;
    }
};
// @lc code=end
