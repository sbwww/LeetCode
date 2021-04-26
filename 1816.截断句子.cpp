/*
 * @lc app=leetcode.cn id=1816 lang=cpp
 *
 * [1816] 截断句子
 */

// @lc code=start
class Solution {
  public:
    string truncateSentence(string s, int k) {
        int len = s.size();
        int i;
        for (i = 0; i < len; ++i) {
            if (s[i] == ' ') {
                --k;
            }
            if (k == 0)
                break;
        }
        return s.substr(0, i);
    }
};
// @lc code=end
