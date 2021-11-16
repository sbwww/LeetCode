/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> num_set;
        for (const int &num : nums)
            num_set.insert(num); // O(1)

        int ans = 0;
        for (const int &num : num_set) {
            if (num_set.find(num - 1) == num_set.end()) {
                int tmp_num = num;
                int tmp_ans = 1;

                while (num_set.find(tmp_num + 1) != num_set.end()) {
                    ++tmp_num;
                    ++tmp_ans;
                }

                ans = max(ans, tmp_ans);
            }
        }

        return ans;
    }
};
// @lc code=end
