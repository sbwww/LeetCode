/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] 有效的括号字符串
 */

// @lc code=start
class Solution {
  public:
    bool checkValidString(string s) {
        stack<int> left_brac_stack;
        stack<int> star_stack;
        int n = s.size();

        for (int i = 0; i < n; ++i)
            if (s[i] == '(')
                left_brac_stack.push(i);
            else if (s[i] == '*')
                star_stack.push(i);
            else if (!left_brac_stack.empty())
                left_brac_stack.pop();
            else if (!star_stack.empty())
                star_stack.pop();
            else
                return false;

        while (!left_brac_stack.empty() && !star_stack.empty()) {
            int left_index = left_brac_stack.top();
            left_brac_stack.pop();
            int star_index = star_stack.top();
            star_stack.pop();
            if (left_index > star_index)
                return false;
        }

        return left_brac_stack.empty();
    }
};
// @lc code=end
