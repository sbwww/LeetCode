/*
 * @lc app=leetcode.cn id=1074 lang=cpp
 *
 * [1074] 元素和为目标值的子矩阵数量
 */

// @lc code=start
class Solution {
  private:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0, pre = 0;
        for (auto &x : nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end())
                cnt += mp[pre - k];
            ++mp[pre];
        }
        return cnt;
    }

  public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            vector<int> preSum(n);
            for (int j = i; j < m; ++j) {
                for (int c = 0; c < n; ++c)
                    preSum[c] += matrix[j][c];

                unordered_map<int, int> mp;
                mp[0] = 1;
                int cnt = 0, pre = 0;
                for (auto &x : preSum) {
                    pre += x;
                    if (mp.find(pre - target) != mp.end())
                        cnt += mp[pre - target];
                    ++mp[pre];
                }

                ans += cnt;
            }
        }
        return ans;
    }
};
// @lc code=end
