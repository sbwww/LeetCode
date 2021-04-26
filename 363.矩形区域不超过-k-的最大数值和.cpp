/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */

// @lc code=start
class Solution {
  public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = INT_MIN;
        for (int c_left = 0; c_left < col; ++c_left) {
            vector<int> preSum(row);
            for (int c_right = c_left; c_right < col; ++c_right) {
                for (int r = 0; r < row; ++r) {
                    preSum[r] += matrix[r][c_right];
                }

                set<int> sumSet{0};
                int s = 0;
                for (int v : preSum) {
                    s += v;
                    auto lb = sumSet.lower_bound(s - k);
                    if (lb != sumSet.end()) {
                        ans = max(ans, s - *lb);
                    }
                    sumSet.insert(s);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
