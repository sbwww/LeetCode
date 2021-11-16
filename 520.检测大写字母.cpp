/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
class Solution {
  public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int cnt = 0;
        for (auto &i : word)
            if (isupper(i))
                ++cnt;
        if (cnt == n)
            return true;
        if (cnt == 1 && isupper(word[0]))
            return true;
        if (cnt == 0)
            return true;
        return false;
    }
};
// @lc code=end
