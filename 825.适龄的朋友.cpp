/*
 * @lc app=leetcode.cn id=825 lang=cpp
 *
 * [825] 适龄的朋友
 */

// @lc code=start
class Solution {
  public:
    int numFriendRequests(vector<int> &ages) {
        int MAXAGE = 120;
        vector<int> cnt(MAXAGE + 1, 0);
        for (auto &age : ages)
            ++cnt[age];

        vector<int> pre(MAXAGE + 1, 0);
        for (int i = 1; i <= MAXAGE; ++i)
            pre[i] = pre[i - 1] + cnt[i];

        int ans = 0;
        for (int i = 15; i <= MAXAGE; ++i) {
            if (cnt[i]) {
                int bound = i * 0.5 + 8;
                ans += cnt[i] * (pre[i] - pre[bound - 1] - 1);
            }
        }
        return ans;
    }
};
// @lc code=end
