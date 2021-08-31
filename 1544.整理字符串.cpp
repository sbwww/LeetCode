/*
 * @lc app=leetcode.cn id=1544 lang=cpp
 *
 * [1544] 整理字符串
 */

// @lc code=start
class Solution {
  public:
    string ans;
    string makeGood(string s) {
        for (auto c : s) {
            if (isupper(ans.back()) && ans.back() + 'a' - 'A' == c ||
                islower(ans.back()) && ans.back() + 'A' - 'a' == c)
                ans.pop_back();
            else
                ans.push_back(c);
        }
        return ans;
    }
};
// @lc code=end
