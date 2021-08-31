/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
  public:
    bool needRev(char c) {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' || //
               c == 'i' || c == 'I' || c == 'o' || c == 'O' || //
               c == 'u' || c == 'U';
    }

    string reverseVowels(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            while (i < n && !needRev(s[i]))
                ++i;

            while (j > 0 && !needRev(s[j]))
                --j;

            if (i < j) {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }

        return s;
    }
};
// @lc code=end
