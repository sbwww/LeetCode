/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
  public:
    set<long long> s;
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            auto it = s.lower_bound(
                (long long)(nums[i]) - t
            );
            if (
                (it != s.end()) && 
                ((*it) <= (long long)(nums[i]) + t)
            )
                return true;
            s.insert(nums[i]);
            if (i >= k)
                s.erase(nums[i - k]);
        }
        return false;
    }
};
// @lc code=end
