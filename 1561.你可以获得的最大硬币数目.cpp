/*
 * @lc app=leetcode.cn id=1561 lang=cpp
 *
 * [1561] 你可以获得的最大硬币数目
 */

// @lc code=start
class Solution {
  public:
    int maxCoins(vector<int> &piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int rounds = n / 3;
        int coins = 0;
        int index = n - 2;
        for (int i = 0; i < rounds; ++i) {
            coins += piles[index];
            index -= 2;
        }
        return coins;
    }
};
// @lc code=end
