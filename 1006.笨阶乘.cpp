/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */

// @lc code=start
class Solution {
  public:
    int clumsy(int N) {
        int ans = 0;
        int times = N / 4;
        int num = N;
        int flag = 1;
        if (times >= 1) {
            ans = num * (num - 1) / (num - 2) + (num - 3);
            num -= 4;
            for (int i = 1; i < times; ++i) {
                ans -= num * (num - 1) / (num - 2) - (num - 3);
                num -= 4;
            }
            flag = -1;
        }
        int res = N % 4;
        switch (res) {
        case 3:
            ans += 6 * flag;
            break;
        case 2:
            ans += 2 * flag;
            break;
        case 1:
            ans += 1 * flag;
            break;
        case 0:
            break;
        default:
            break;
        }
        return ans;
    }
};
// @lc code=end
