/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int len = nums.size();
        if (len <= 2)
            return len;
        int i = 2;
        int j = 2;
        for (; j < len; ++j) {
            if (nums[i - 2] != nums[j]) {
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
};

// 0,0,1,1,1,1,2,3,3
// 0 0 1 1 2 3 3

// @lc code=end
