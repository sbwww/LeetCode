/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        int ans = nums[0];
        int maxF = ans;
        int minF = ans;
        for (int i = 1; i < n; ++i) {
            int tmp = nums[i];
            int mx = maxF * tmp;
            int mn = minF * tmp;

            maxF = max(mx, max(tmp, mn));
            minF = min(mn, min(tmp, mx));
            ans = max(maxF, ans);
        }
        return ans;
    }
};
// @lc code=end
