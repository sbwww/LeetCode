/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
class Solution {
  public:
    vector<int> a;
    int sum = 0;
    Solution(vector<int> &w) {
        int n = w.size();
        for (int i = 0; i < n; ++i) {
            sum += w[i];
            a.push_back(sum - 1);
        }
    }
    int pickIndex() {
        int t = rand() % sum;
        return lower_bound(a.begin(), a.end(), t) - a.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
