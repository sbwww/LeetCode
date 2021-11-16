/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int xorsum = 0;
        for (auto &i : nums)
            xorsum ^= i;

        return xorsum;
    }
};
// @lc code=end
