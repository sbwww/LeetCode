/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
  public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (mid == 0)
                return right;
            if (mid == n - 1)
                return left;
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid - 1] < arr[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end
