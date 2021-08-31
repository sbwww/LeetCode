/*
 * @lc app=leetcode.cn id=1720 lang=cpp
 *
 * [1720] 解码异或后的数组
 */

// @lc code=start
class Solution {
  public:
    vector<int> decode(vector<int> &encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for (auto i : encoded) {
            first ^= i;
            ans.push_back(first);
        }
        return ans;
    }
};
// @lc code=end
