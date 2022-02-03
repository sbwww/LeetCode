/*
 * @lc app=leetcode.cn id=2000 lang=cpp
 *
 * [2000] 反转单词前缀
 */

// @lc code=start
class Solution {
  public:
    string reversePrefix(string word, char ch) {
        int len = word.length();
        for (int i = 0; i < len; ++i) {
            if (word[i] == ch) {
                reverse(word.begin(), word.begin() + i + 1);
                break;
            }
        }
        return word;
    }
};
// @lc code=end
