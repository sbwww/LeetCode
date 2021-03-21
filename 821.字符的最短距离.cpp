/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// @lc code=start
// #include <bits/stdc++.h>
// using namespace std;
// aaba b

class Solution {
  public:
    const int MAXN = 1e5 + 5;
    vector<int> shortestToChar(string S, char C) {
        int n = S.length();
        int C_index = -1;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            if (S[i] == C) {
                ans[i] = 0;
                C_index = i;
            } else if (C_index >= 0) {
                ans[i] = abs(i - C_index);
            } else {
                ans[i] = -1;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (S[i] == C) {
                C_index = i;
            } else if (ans[i] < 0) {
                ans[i] = C_index - i;
            } else {
                ans[i] = min(ans[i], abs(i - C_index));
            }
        }
        return ans;
    }
};
// @lc code=end
