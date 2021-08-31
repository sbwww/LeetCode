/*
 * @lc app=leetcode.cn id=1734 lang=cpp
 *
 * [1734] 解码异或后的排列
 */

// @lc code=start
class Solution {
  public:
    vector<int> decode(vector<int> &encoded) {
        int n = encoded.size() + 1;

        int total = 0;
        for (int i = 1; i <= n; ++i)
            total ^= i;

        int odd = 0;
        for (int i = 1; i < n - 1; i += 2)
            odd ^= encoded[i];

        int last = total ^ odd;

        vector<int> ans;
        ans.emplace_back(last);
        for (int i = 0; i < n - 1; ++i) {
            last ^= encoded[i];
            ans.emplace_back(last);
        }

        return ans;
    }
};
// @lc code=end

