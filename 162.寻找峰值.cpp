/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
  public:
    int binarySearch(int left, int right, vector<int> &nums) {
        if (left >= right)
            return left;
        int mid = (left + right) / 2;
        if (nums[mid] > nums[mid + 1])
            return binarySearch(left, mid, nums);
        return binarySearch(mid + 1, right, nums);
    }
    int findPeakElement(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;
        return binarySearch(0, nums.size() - 1, nums);
    }
};
// @lc code=end
