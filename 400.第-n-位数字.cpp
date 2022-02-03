/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// @lc code=start
class Solution {
  public:
    int findNthDigit(int n) {
        /*
        1-9     9*1=9
        10-99   90*2=180
        100-999 900*3=2700
        */
        int d = 1;
        int count = 9;
        while (n > (long long)d * count) {
            n -= d * count;
            ++d;
            count *= 10;
        }
        int index = n - 1;
        int start = (int)pow(10, d - 1);
        int num = start + index / d;
        int digitIndex = index % d;
        int digit = (num / (int)(pow(10, d - digitIndex - 1))) % 10;
        return digit;
    }
};
// @lc code=end
