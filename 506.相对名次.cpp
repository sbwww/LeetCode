/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> findRelativeRanks(vector<int> &score) {
        int n = score.size();
        vector<string> ans;
        vector<int> sorted_score = score;
        sort(sorted_score.begin(), sorted_score.end(), greater<int>());
        map<int, string> medal;
        medal[sorted_score[0]] = "Gold Medal";
        if (n > 1)
            medal[sorted_score[1]] = "Silver Medal";
        if (n > 2)
            medal[sorted_score[2]] = "Bronze Medal";
        for (int i = 3; i < n; ++i)
            medal[sorted_score[i]] = to_string(i + 1);
        for (int i = 0; i < n; ++i)
            ans.emplace_back(medal[score[i]]);
        return ans;
    }
};
// @lc code=end
