/*
 * @lc app=leetcode.cn id=1833 lang=cpp
 *
 * [1833] 雪糕的最大数量
 */

// @lc code=start
class Solution {
  public:
    int maxIceCream(vector<int> &costs, int coins) {
        int cnt = 0;
        sort(costs.begin(), costs.end());
        for (auto c : costs) {
            if (coins - c >= 0) {
                ++cnt;
                coins -= c;
            }
        }
        return cnt;
    }
};
// @lc code=end
