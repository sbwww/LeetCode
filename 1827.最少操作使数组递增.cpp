/*
 * @lc app=leetcode.cn id=1827 lang=cpp
 *
 * [1827] 最少操作使数组递增
 */

// @lc code=start
class Solution {
  public:
    int minOperations(vector<int> &nums) {
        int last = 0;
        int ans = 0;
        for (auto i : nums) {
            if (i <= last) {
                ans += last + 1 - i;
                last = last + 1;
            } else {
                last = i;
            }
        }
        return ans;
    }
};
// @lc code=end
