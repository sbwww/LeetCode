/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int once = 0;
        int twice = 0;
        for (auto i : nums) {
            once = ~twice & (once ^ i);
            // cout << "once : " << bitset<32>(once) << endl;
            twice = ~once & (twice ^ i);
            // cout << "twice : " << bitset<32>(twice) << endl;
        }
        return once;
    }
};
// @lc code=end
