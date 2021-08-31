/*
 * @lc app=leetcode.cn id=1588 lang=cpp
 *
 * [1588] 所有奇数长度子数组的和
 */

// @lc code=start
class Solution {
  public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int left = i;
            int right = n - i - 1;
            int leftOdd = (left + 1) / 2;
            int rightOdd = (right + 1) / 2;
            int leftEven = left / 2 + 1;
            int rightEven = right / 2 + 1;
            ans += arr[i] * (leftOdd * rightOdd + leftEven * rightEven);
        }

        return ans;
    }
};
// @lc code=end
