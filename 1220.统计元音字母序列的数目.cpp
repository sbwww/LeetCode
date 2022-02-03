/*
 * @lc app=leetcode.cn id=1220 lang=cpp
 *
 * [1220] 统计元音字母序列的数目
 */

// @lc code=start
class Solution {
  public:
    int countVowelPermutation(int n) {
        const int MOD = 1e9 + 7;
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int k = 2; k <= n; ++k) {
            long aa = (e + i + u) % MOD;
            long ee = (a + i) % MOD;
            long ii = (e + o) % MOD;
            long oo = i;
            long uu = (o + i) % MOD;
            a = aa;
            e = ee;
            i = ii;
            o = oo;
            u = uu;
        }
        return (a + e + i + o + u) % MOD;
    }
};
// @lc code=end
