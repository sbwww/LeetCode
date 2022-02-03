/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution {
  public:
    bool increasingTriplet(vector<int> &nums) {
        int a = INT_MAX;
        int b = INT_MAX;
        for (auto &i : nums)
            if (i <= a)
                a = i;
            else if (i <= b)
                b = i;
            else
                return true;
        return false;
    }
};
// @lc code=end
