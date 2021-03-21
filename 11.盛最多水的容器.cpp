/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getArea(int x, int y, int hx, int hy) {
        return abs(x - y) * min(hx, hy);
    }
    int maxArea(vector<int> &height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int ans = 0;
        while (l < r) {
            int tmp = getArea(l, r, height[l], height[r]);
            ans = max(ans, tmp);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
};
// @lc code=end
