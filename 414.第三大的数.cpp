/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
  public:
    int thirdMax(vector<int> &nums) {
        long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
        for (auto &i : nums) {
            if (i > a) {
                c = b;
                b = a;
                a = i;
            } else if (b < i && i < a) {
                c = b;
                b = i;
            } else if (c < i && i < b) {
                c = i;
            }
        }
        return c == LONG_MIN ? a : c;
    }
};
// @lc code=end
