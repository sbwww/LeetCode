/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int ans = 0;
        int vote = 0;
        for (int i : nums) {
            if (vote == 0)
                ans = i;
            vote += (i == ans) ? 1 : -1;
        }
        return ans;
    }
};
// @lc code=end
