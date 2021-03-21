/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int trap(vector<int> &height) {
        int n = height.size();
        int ans = 0;
        int tmp;
        stack<int> wall;
        for (int i = 0; i < n; ++i) {
            if (height[i] < wall.top()) {
                wall.push(height[i]);
            } else {
                while (height[i] >= wall.top()) {
                    tmp = wall.top();
                    ans += tmp * i;
                    wall.pop();
                }
            }
        }
        while (!wall.empty()) {
            tmp = wall.top();
            ans += tmp;
            wall.pop();
        }
        return ans;
    }
};
// @lc code=end
