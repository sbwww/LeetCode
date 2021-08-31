/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
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

