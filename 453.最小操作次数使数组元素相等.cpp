/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution {
  public:
    int minMoves(vector<int> &nums) {
        unsigned long long sum = 0;
        int min_num = nums[0];
        for (auto &i : nums) {
            min_num = min(min_num, i);
            sum += i;
        }
        return sum - min_num * nums.size();
    }
};
// @lc code=end
