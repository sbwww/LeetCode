/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution {
  public:
    int distributeCandies(vector<int> &candyType) {
        unordered_set<int> st(candyType.begin(), candyType.end());
        return min(candyType.size() / 2, st.size());
    }
};
// @lc code=end
