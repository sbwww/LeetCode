/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution {
  public:
    int tribonacci(int n) {
        int T_n2 = 1, T_n1 = 1, T_n = 0;
        int T_n3;
        switch (n) {
        case 0:
            return 0;
        case 1:
        case 2:
            return 1;
        default:
            break;
        }
        for (int i = 0; i < n - 2; ++i) {
            T_n3 = T_n + T_n1 + T_n2;
            T_n = T_n1;
            T_n1 = T_n2;
            T_n2 = T_n3;
        }
        return T_n3;
    }
};
// @lc code=end
