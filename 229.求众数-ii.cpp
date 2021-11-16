/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution {
  public:
    vector<int> majorityElement(vector<int> &nums) {
        int n = nums.size();
        int threshold = n / 3;

        vector<int> ans;
        unordered_map<int, int> cnt;
        for (auto &i : nums) {
            if ((++cnt[i]) > threshold) {
                if (ans.size() == 0) {
                    ans.emplace_back(i);
                } else if (ans.size() == 1) {
                    if (ans[0] != i) {
                        ans.emplace_back(i);
                        return ans;
                    }
                } else {
                    return ans;
                }
            }
        }

        return ans;
    }
};
// @lc code=end
