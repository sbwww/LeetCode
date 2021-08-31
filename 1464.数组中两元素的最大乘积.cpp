/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start
class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        priority_queue<int> pq;
        for (auto &i : nums) {
            pq.push(i);
        }

        int ans = pq.top() - 1;
        pq.pop();
        ans *= (pq.top() - 1);

        return ans;
    }
};
// @lc code=end
