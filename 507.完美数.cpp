/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

// @lc code=start
class Solution {
  public:
    bool checkPerfectNumber(int num) {
        if (num == 1)
            return false;

        int sum = 1;
        int lim = sqrt(num);
        for (int d = 2; d <= lim; ++d) {
            if (num % d == 0) {
                sum += d;
                if (d * d < num)
                    sum += num / d;
            }
        }
        return sum == num;
    }
};
// @lc code=end
