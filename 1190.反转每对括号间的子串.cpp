/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */

// @lc code=start
class Solution {
  public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string ans;
        for (auto &ch : s) {
            if (ch == '(') {
                stk.push(ans);
                ans = "";
            } else if (ch == ')') {
                reverse(ans.begin(), ans.end());
                ans = stk.top() + ans;
                stk.pop();
            } else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
// @lc code=end
