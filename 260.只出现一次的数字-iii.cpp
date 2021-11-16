/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
  public:
    vector<int> singleNumber(vector<int> &nums) {
        // x ^ x = 0
        // 0 ^ x = x
        // 出现两次的必然都变成 0
        int xorsum = 0;
        for (int num : nums)
            xorsum ^= num;
        // xorsum = a ^ b
        // 其中 a 和 b 是出现两次的数

        // 防止溢出
        // x ^ (-x) 取出 x 二进制表示中最低位的 1
        int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));

        int type1 = 0, type2 = 0;

        for (int num : nums)
            if (num & lsb)
                type1 ^= num;
            else
                type2 ^= num;

        return {type1, type2};
    }
};
// @lc code=end
