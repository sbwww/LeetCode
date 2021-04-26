/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        // 记录频率
        // 不同数组合，相同数不同个数
        map<int, int> dic;
        for (auto i : nums)
            dic[i] = dic[i] + 1;

        // for (auto p : dic)
        //     cout << p.first << " " << p.second << endl;

        vector<vector<int>> ans;
        ans.push_back(vector<int>());

        for (auto p : dic) {
            vector<vector<int>> tmp = ans;

            for (auto subset : tmp) {
                auto t = subset;
                for (int k = 0; k < p.second; ++k) {
                    t.push_back(p.first);
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
