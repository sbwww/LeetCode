/*
 * @lc app=leetcode.cn id=390 lang=cpp
 *
 * [390] 消除游戏
 */

// @lc code=start
class Solution {
  public:
    int lastRemaining(int n) {
        int a1 = 1;
        int flag = true;
        int cnt = n, step = 1;
        while (cnt > 1) {
            if (flag)
                a1 = a1 + step;
            else
                a1 = (cnt % 2 == 0) ? a1 : a1 + step;
            flag = !flag;
            cnt = cnt >> 1;
            step = step << 1;
        }
        return a1;
    }
};
// @lc code=end
