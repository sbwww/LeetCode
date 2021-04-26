/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
  public:
    bool binarySearch(vector<int> nums, int target, int left, int right) {
        if (left > right)
            return false;
        if (left == right)
            return (nums[left] == target);
        int mid = (left + right) / 2;
        if (target < nums[mid])
            return binarySearch(nums, target, left, mid);
        if (target > nums[mid])
            return binarySearch(nums, target, mid + 1, right);
        return true;
    }
    bool search(vector<int> &nums, int target) {
        int len = nums.size();
        int tmp = nums[0];
        for (int i = 0; i < len; ++i) {
            if (nums[i] == target)
                return true;
            if (nums[i] < tmp)
                return binarySearch(nums, target, i, len - 1);
            tmp = nums[i];
        }
        return false;
    }
};
// @lc code=end
