/*
 * @lc app=leetcode.cn id=1296 lang=cpp
 *
 * [1296] 划分数组为连续数字的集合
 */

// @lc code=start
class Solution {
  public:
    bool isPossibleDivide(vector<int> &nums, int k) {
        int n = nums.size();
        if (n % k != 0)
            return false;
        map<int, int> cnt;
        for (auto &i : nums)
            ++cnt[i];

        int cnt_size = cnt.size();
        while (cnt_size > 0) {
            int start = cnt.begin()->first;
            for (int i = 0; i < k; ++i) {
                int idx = start + i;
                if (cnt[idx] == 0)
                    return false;
                if (--cnt[idx] == 0) {
                    cnt.erase(idx);
                    --cnt_size;
                }
            }
        }

        return true;
    }
};
// @lc code=end
