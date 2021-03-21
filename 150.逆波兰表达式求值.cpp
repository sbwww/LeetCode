/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    stack<int> numbers;

    int calculate(char token) {
        int op2 = numbers.top();
        numbers.pop();
        int op1 = numbers.top();
        numbers.pop();
        int ans = 0;
        switch (token) {
        case '+':
            ans = op1 + op2;
            break;
        case '-':
            ans = op1 - op2;
            break;
        case '*':
            ans = op1 * op2;
            break;
        case '/':
            ans = op1 / op2;
            break;
        }
        return ans;
    }

    int evalRPN(vector<string> &tokens) {
        // numbers.push(0);
        for (auto &str : tokens) {
            char c = str[0];
            if (isdigit(c) || (c == '-' && str != "-")) {
                numbers.push(stod(str));
            } else {
                numbers.push(calculate(str[0]));
            }
        }
        return numbers.top();
    }
};
// @lc code=end
