/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<string> ans;
    void dfs(string tmp, int n, int left, int right) {
        if (left == n && right == n) {
            ans.push_back(tmp);
            return;
        }
        if (left < n) {
            dfs(tmp + "(", n, left + 1, right);
        }
        if (left > right) {
            dfs(tmp + ")", n, left, right + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string tmp = "(";
        int left = 1;
        int right = 0;
        dfs(tmp, n, left, right);
        return ans;
    }
};
// @lc code=end
