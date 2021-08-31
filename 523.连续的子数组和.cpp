/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start
class Solution {
  public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        if (n < 2)
            return false;

        unordered_map<int, int> mp;
        mp[0] = -1;
        int preSum = 0;
        for (int i = 0; i < n; ++i) {
            preSum = (preSum + nums[i]) % k;
            if (mp.count(preSum)) {
                int prevIndex = mp[preSum];
                if (i - prevIndex >= 2) {
                    return true;
                }
            } else {
                mp[preSum] = i;
            }
        }
        return false;
    }
};
// @lc code=end
