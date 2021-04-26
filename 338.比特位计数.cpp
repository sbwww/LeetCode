/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
  public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        // int high = 0;
        // for (int i = 1; i <= num; ++i) {
        //     if ((i & (i - 1)) == 0)
        //         high = i;
        //     ans[i] = ans[i - high] + 1;
        // }
        for (int i = 1; i <= num; ++i) {
            if (i & 1)
                ans[i] = ans[i - 1] + 1;
            else
                ans[i] = ans[i >> 1];
        }
        return ans;
    }
};
// @lc code=end
