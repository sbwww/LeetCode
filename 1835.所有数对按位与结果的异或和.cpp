/*
 * @lc app=leetcode.cn id=1835 lang=cpp
 *
 * [1835] 所有数对按位与结果的异或和
 */

// @lc code=start
class Solution {
  public:
    int getXORSum(vector<int> &arr1, vector<int> &arr2) {
        int tmp1 = 0;
        int tmp2 = 0;
        for (auto i : arr1)
            tmp1 ^= i;
        for (auto i : arr2)
            tmp2 ^= i;
        return tmp1 & tmp2;
    }
};
// @lc code=end
