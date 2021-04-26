/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        int i = 1;
        int j = 1;

        while (i < n) {
            int tmp = nums[i - 1];
            while (i < n && nums[i] == tmp)
                ++i;
            if (i < n)
                nums[j++] = nums[i++];
        }
        return j;
    }
};
// @lc code=end
