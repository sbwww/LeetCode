/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
  public:
    int quick_sort(vector<int> &nums, int l, int r, int k) {
        if (l >= r)
            return nums[l];

        int i = l - 1, j = r + 1, x = nums[(l + r) / 2];
        while (i < j) {
            do
                ++i;
            while (nums[i] > x);

            do
                --j;
            while (nums[j] < x);

            if (i < j)
                swap(nums[i], nums[j]);
        }

        if (j - l + 1 >= k)
            return quick_sort(nums, l, j, k);
        else
            return quick_sort(nums, j + 1, r, k - (j - l + 1));
    }

    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();
        
        return quick_sort(nums, 0, n - 1, k);
    }
};
// @lc code=end
