/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution {
  public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int, vector<int>, less<int>> pq;

        for (auto i : stones)
            pq.push(i);

        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(abs(a - b));
        }
        return pq.top();
    }
};
// @lc code=end
