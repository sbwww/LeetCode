/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// @lc code=start
class Solution {
  public:
    vector<string> findWords(vector<string> &words) {
        vector<string> ans;
        string rowIndex = "12210111011122000010020202";
        for (auto &word : words) {
            bool isValid = true;
            char idx = rowIndex[tolower(word[0]) - 'a'];
            for (auto &c : word) {
                if (rowIndex[tolower(c) - 'a'] != idx) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }
};
// @lc code=end
