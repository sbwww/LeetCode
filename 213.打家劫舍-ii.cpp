/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rob_1(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        int tmp = 0;
        int last_1 = max(nums[0], nums[1]);
        int last_2 = nums[0];
        for (int i = 2; i < n; ++i) {
            tmp = last_1;
            last_1 = max(last_1, last_2 + nums[i]);
            last_2 = tmp;
        }
        return max(last_1, last_2);
    }

    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        vector<int>::iterator first = nums.begin();
        vector<int>::iterator last = nums.end();
        vector<int> nums1(first, last - 1);
        vector<int> nums2(first + 1, last);
        return max(rob_1(nums1), rob_1(nums2));
    }
};
// @lc code=end
