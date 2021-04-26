/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 *
 * [1822] 数组元素积的符号
 */

// @lc code=start
class Solution {
  public:
    int arraySign(vector<int> &nums) {
        int ans = 1;
        for (auto i : nums) {
            if (i == 0)
                return 0;
            if (i < 0)
                ans *= (-1);
        }
        return ans;
    }
};
// @lc code=end
