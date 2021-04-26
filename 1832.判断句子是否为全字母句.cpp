/*
 * @lc app=leetcode.cn id=1832 lang=cpp
 *
 * [1832] 判断句子是否为全字母句
 */

// @lc code=start
class Solution {
  public:
    bool checkIfPangram(string sentence) {
        vector<bool> flag(26, false);
        for (auto c : sentence) {
            flag[c - 'a'] = 1;
        }
        for (auto f : flag) {
            if (!f)
                return false;
        }
        return true;
    }
};
// @lc code=end
