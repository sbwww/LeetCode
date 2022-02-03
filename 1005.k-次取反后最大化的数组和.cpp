/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
  public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int minn = INT_MAX;
        for (auto &i : nums) {
            if (i >= 0) {
                minn = min(minn, i);
            } else {
                if (k > 0) {
                    i = -i;
                    minn = min(minn, i);
                    --k;
                }
            }
            sum += i;
        }
        if (k > 0)
            if (k & 1)
                sum -= 2 * minn;

        return sum;
    }
};
// @lc code=end
