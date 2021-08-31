/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start
class Solution {
  public:
    bool stoneGame(vector<int> &piles) {
        // 将石子堆分组，奇数位为一组，偶数位为一组
        // 如 5 4 3 2 1 2
        // 有 5   3   1   = 9
        // 和   4   2   2 = 8
        // 先手选择大的那一堆，然后无论后手选什么，只选这一堆里的
        // 如 先手选 5，后手选 4，则先手再选 3
        // 若 先手选 5，后手选 2，则先手再选 1
        // 因为先手可以选择更大的一堆，所以先手必胜
        return true;
    }
};
// @lc code=end
