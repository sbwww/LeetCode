/*
 * @lc app=leetcode.cn id=810 lang=cpp
 *
 * [810] 黑板异或游戏
 */

// @lc code=start
class Solution {
  public:
    bool xorGame(vector<int> &nums) {
        if ((nums.size() & 1) == 0)
            return true;

        int xorSum = 0;
        for (auto i : nums)
            xorSum ^= i;

        return xorSum == 0;
    }
};
// @lc code=end
