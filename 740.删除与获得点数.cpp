/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除与获得点数
 */

// @lc code=start
class Solution {
    int MAXN = 1e4 + 1;

  public:
    int deleteAndEarn(vector<int> &nums) {
        vector<int> val(MAXN, 0);
        int maxVal = 0;
        for (auto i : nums) {
            val[i] += i;
            maxVal = max(maxVal, i);
        }

        int first = val[0];
        int second = max(val[0], val[1]);
        for (int i = 2; i < maxVal + 1; ++i) {
            int tmp = second;
            second = max(first + val[i], second);
            first = tmp;
        }
        return second;
    }
};
// @lc code=end
