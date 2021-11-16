/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
  public:
    int countSegments(string s) {
        int cnt = 0;
        int tmp_len = 0;
        for (auto &c : s) {
            if (c == ' ') {
                if (tmp_len > 0)
                    ++cnt;
                tmp_len = 0;
            } else {
                ++tmp_len;
            }
        }
        if (tmp_len > 0)
            ++cnt;
        return cnt;
    }
};
// @lc code=end
