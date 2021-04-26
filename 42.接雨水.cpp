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
        if (height.size() <= 2)
            return 0;

        int ans = 0;
        stack<int> s;
        s.push(0);
        for (int i = 1; i < height.size(); ++i) {
            while (height[i] > height[s.top()]) {
                int top = s.top();
                s.pop();
                if (s.empty())
                    break;
                int distance = i - s.top() - 1;
                int bounded_height =
                    min(height[i], height[s.top()]) - height[top];
                ans += distance * bounded_height;
            }
            s.push(i);
        }
        return ans;
    }
};
// @lc code=end
