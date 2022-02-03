/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */

// @lc code=start
class Solution {
  public:
    const int MOD = 1337;

    int qpow(int x, int n) {
        int res = 1;
        while (n) {
            if (n & 1)
                res = (long)res * x % MOD;
            x = (long)x * x % MOD;
            n >>= 1;
        }
        return res;
    }

    int superPow(int a, vector<int> &b) {
        int ans = 1;
        for (auto &i : b)
            ans = (long)qpow(ans, 10) * qpow(a, i) % MOD;

        return ans;
    }
};
// @lc code=end
