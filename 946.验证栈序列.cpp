/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution {
  public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> stk;
        int n = pushed.size();
        int push_idx = 0;
        int pop_idx = 0;
        while (push_idx < n || pop_idx < n) {
            if (!stk.empty() && stk.top() == popped[pop_idx]) {
                stk.pop();
                ++pop_idx;
            } else {
                if (push_idx < n) {
                    if (pushed[push_idx] != popped[pop_idx]) {
                        stk.push(pushed[push_idx]);
                        ++push_idx;
                    } else {
                        ++push_idx;
                        ++pop_idx;
                    }
                } else {
                    if (stk.top() == popped[pop_idx]) {
                        stk.pop();
                        ++pop_idx;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
