/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
class Solution {
  public:
    int findJudge(int n, vector<vector<int>> &trust) {
        vector<int> people(n + 1, 0);
        int ans = -1;
        for (auto &t : trust) {
            people[t[0]] = -1;
            if (people[t[1]] != -1)
                ++people[t[1]];
        }
        for (int i = 1; i <= n; ++i)
            if (people[i] == n - 1)
                ans = i;

        return ans;
    }
};
// @lc code=end
