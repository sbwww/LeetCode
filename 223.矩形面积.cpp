/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution {
  public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                    int bx2, int by2) {
        int S1 = (ax1 - ax2) * (ay1 - ay2);
        int S2 = (bx1 - bx2) * (by1 - by2);
        int S12 = max(0, (min(bx2, ax2) - max(ax1, bx1))) *
                  max(0, (min(by2, ay2) - max(ay1, by1)));
        return S1 + S2 - S12;
    }
};
// @lc code=end
