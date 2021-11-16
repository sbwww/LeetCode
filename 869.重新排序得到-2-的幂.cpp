/*
 * @lc app=leetcode.cn id=869 lang=cpp
 *
 * [869] 重新排序得到 2 的幂
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> tbl = {{},
                               {1, 2, 4, 8},
                               {16, 32, 64},
                               {128, 256, 512},
                               {1024, 2048, 4096, 8192},
                               {16384, 32768, 65536},
                               {131072, 262144, 524288},
                               {1048576, 2097152, 4194304, 8388608},
                               {16777216, 33554432, 67108864},
                               {134217728, 268435456, 536870912}};

    bool check(int src, int tar) {
        vector<int> cnt(10, 0);
        for (auto &i : to_string(src))
            ++cnt[i - '0'];

        for (auto &i : to_string(tar))
            if (--cnt[i - '0'] < 0)
                return false;

        return true;
    }

    bool reorderedPowerOf2(int n) {
        double eps = 1e-10;
        int bit = ceil(log10(n) + eps);
        if (bit < 1 || bit > 9)
            return false;

        for (auto &tar : tbl[bit])
            if (check(n, tar))
                return true;

        return false;
    }
};
// @lc code=end
