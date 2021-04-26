/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */

// @lc code=start
class Solution {
  public:
    vector<int> pancakeSort(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans;
        for (int i = n - 1; i >= 0; --i) {
            int max_index =
                max_element(arr.begin(), arr.begin() + i + 1) - arr.begin();
            if (max_index != i) {
                if (max_index != 0) {
                    reverse(arr.begin(), arr.begin() + max_index + 1);
                    ans.push_back(max_index + 1);
                }
                reverse(arr.begin(), arr.begin() + i + 1);
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
// 3 2 4 1
// 4 2 3 1  // 3
// 1 3 2 4  // 4
// 3 1 2 4  // 2
// 2 1 3 4  // 3
//
// @lc code=end
