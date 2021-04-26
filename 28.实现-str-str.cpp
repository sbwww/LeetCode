/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
  public:
    int strStr(string text, string pattern) {
        int n = text.size();
        int m = pattern.size();

        if (m == 0)
            return 0;

        vector<int> next(m);

        int i = 0;
        int j = 0;

        for (i = 1, j = 0; i < m; ++i) {
            while (j > 0 && pattern[i] != pattern[j])
                j = next[j - 1];

            if (pattern[i] == pattern[j])
                ++j;

            next[i] = j;
        }

        for (i = 0, j = 0; i < n; ++i) {
            while (j > 0 && text[i] != pattern[j])
                j = next[j - 1];

            if (text[i] == pattern[j])
                ++j;

            if (j == m)
                return i - m + 1;
        }
        return -1;
    }
};
// @lc code=end
