/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */

// @lc code=start
class Solution {
  public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        if (n != goal.size())
            return false;

        if (s == goal) {
            vector<int> count(26);
            for (int i = 0; i < s.size(); ++i) {
                ++count[s[i] - 'a'];
                if (count[s[i] - 'a'] > 1)
                    return true;
            }
            return false;
        }

        char c1 = ' ';
        char c2 = ' ';
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] != goal[i]) {
                if (c1 == ' ' && c2 == ' ') {
                    c1 = s[i];
                    c2 = goal[i];
                } else {
                    if (flag)
                        return false;

                    if (s[i] == c2 && goal[i] == c1)
                        flag = true;
                    else
                        return false;
                }
            }
        }
        if (flag)
            return true;

        if (c1 == ' ' && c2 == ' ')
            return true;
        return false;
    }
};
// @lc code=end
