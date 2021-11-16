/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
  public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> ans;
        unordered_map<string, int> mp;
        for (int i = 0; i <= n - 10; ++i) {
            string tmp = s.substr(i, 10);
            ++mp[tmp];
            if (mp[tmp] == 2) // >1 的话会重复算，==2 不会
                ans.emplace_back(tmp);
        }

        return ans;
    }
};
// @lc code=end
