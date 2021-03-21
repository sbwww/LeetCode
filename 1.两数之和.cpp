/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ans;
        unordered_map<int, int> hashMap;
        int res;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            res = target - nums[i];
            unordered_map<int, int>::iterator it = hashMap.find(res);
            if (it != hashMap.end()) {
                return vector<int>({it->second, i});
            }
            hashMap[nums[i]] = i;
        }
        return vector<int>({target, 0});
    }
};
// @lc code=end
