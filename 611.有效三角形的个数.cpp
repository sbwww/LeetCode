/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
class Solution {
  public:
    int triangleNumber(vector<int> &nums) {
        int n = nums.size();
        if (n < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0)
                continue;
            int k = i;
            for (int j = i + 1; j < n; ++j) {
                while (k + 1 < n && nums[k + 1] < nums[i] + nums[j])
                    ++k;
                ans += max(k - j, 0);
            }
        }
        return ans;
    }
};
// @lc code=end
