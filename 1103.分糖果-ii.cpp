/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 *
 * [1103] 分糖果 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> distributeCandies(int candies, int num_people) {
        int i = 0;
        vector<int> ans(num_people, 0);
        while (candies) {
            ans[i % num_people] += min(candies, i + 1);
            candies -= min(candies, i + 1);
            ++i;
        }
        return ans;
    }
};
// @lc code=end
