/*
 * @lc app=leetcode.cn id=1310 lang=cpp
 *
 * [1310] 子数组异或查询
 */

// @lc code=start
class Solution {
  public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();

        vector<int> preSum(n + 1, 0);
        for (int i = 0; i < n; ++i)
            preSum[i + 1] = preSum[i] ^ arr[i];

        vector<int> ans;
        for (auto q : queries) {
            ans.emplace_back(preSum[q[1] + 1] ^ preSum[q[0]]);
        }

        return ans;
    }
};
// @lc code=end
