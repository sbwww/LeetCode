/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// 1534236469
// -2147483648
class Solution {
  public:
    const int MAXN = 0x7fffffff;
    const int MINN = 0x80000000;
    int reverse(int x) {
        int ans = 0;
        long long tmp;
        if (x == 0) {
            return 0;
        } else if (x < 0) {
            while (x < 0) {
                tmp = ans * (long long)10 + x % 10;
                if (tmp > MINN)
                    ans = tmp;
                else
                    return 0;
                x /= 10;
            }
        } else {
            while (x > 0) {
                tmp = ans * (long long)10 + x % 10;
                if (tmp < MAXN)
                    ans = tmp;
                else
                    return 0;
                x /= 10;
            }
        }

        return ans;
    }
};
// @lc code=end
