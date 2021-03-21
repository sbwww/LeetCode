/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
  public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> brackets;
        for (int i = 0; i < n; ++i) {
            switch (s[i]) {
            case '(':
                brackets.push(s[i]);
                break;
            case '[':
                brackets.push(s[i]);
                break;
            case '{':
                brackets.push(s[i]);
                break;
            case ')':
                if (brackets.empty() || brackets.top() != '(')
                    return false;
                else
                    brackets.pop();
                break;
            case ']':
                if (brackets.empty() || brackets.top() != '[')
                    return false;
                else
                    brackets.pop();
                break;
            case '}':
                if (brackets.empty() || brackets.top() != '{')
                    return false;
                else
                    brackets.pop();
                break;
            }
        }
        return brackets.empty();
    }
};
// @lc code=end
