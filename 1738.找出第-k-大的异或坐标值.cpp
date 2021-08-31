/*
 * @lc app=leetcode.cn id=1738 lang=cpp
 *
 * [1738] 找出第 K 大的异或坐标值
 */

// @lc code=start
class Solution {
  public:
    int kthLargestValue(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> preSum(n + 1, vector<int>(m + 1, 0));

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                preSum[i][j] = matrix[i - 1][j - 1] ^ preSum[i][j - 1] ^
                               preSum[i - 1][j] ^ preSum[i - 1][j - 1];
                if (pq.size() < k) {
                    pq.push(preSum[i][j]);
                    continue;
                }
                if (preSum[i][j] > pq.top()) {
                    pq.pop();
                    pq.push(preSum[i][j]);
                }
            }
        }

        return pq.top();
    }
};
// @lc code=end
