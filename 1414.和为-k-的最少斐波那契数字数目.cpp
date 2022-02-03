/*
 * @lc app=leetcode.cn id=1414 lang=cpp
 *
 * [1414] 和为 K 的最少斐波那契数字数目
 */

// @lc code=start
class Solution {
  public:
    int findMinFibonacciNumbers(int k) {
        int fib0 = 1;
        int fib1 = 1;
        int fib2;
        for (int i = 0;; ++i) {
            fib2 = fib0 + fib1;
            if (fib2 > k)
                break;
            fib0 = fib1;
            fib1 = fib2;
        }
        int cnt = 0;
        while (k > 0) {
            k -= fib1;
            ++cnt;
            while (fib1 > k) {
                fib2 = fib1;
                fib1 = fib0;
                fib0 = fib2 - fib1;
            }
        }
        return cnt;
    }
};
// @lc code=end
