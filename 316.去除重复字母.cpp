/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
  public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26);
        vector<int> num(26);
        for (char c : s)
            ++num[c - 'a'];

        string ans;
        for (char c : s) {
            if (!vis[c - 'a']) {
                while (!ans.empty() && ans.back() > c) {
                    if (num[ans.back() - 'a'] > 0) {
                        vis[ans.back() - 'a'] = 0;
                        ans.pop_back();
                    } else {
                        break;
                    }
                }
                vis[c - 'a'] = 1;
                ans.push_back(c);
            }
            --num[c - 'a'];
        }
        return ans;
    }
};
// @lc code=end
