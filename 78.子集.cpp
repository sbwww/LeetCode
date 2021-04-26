/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
// class Solution {
//   public:
//     vector<vector<int>> subsets(vector<int> &nums) {
//         int len = nums.size();
//         unsigned long long n = 1 << len;
//         vector<vector<int>> ans;
//         for (int i = 0; i < n; ++i) {
//             vector<int> tmp;
//             for (int j = 0; j < len; ++j) {
//                 if (((i >> j) & 1) == 1) {
//                     tmp.push_back(nums[j]);
//                 }
//             }
//             ans.push_back(tmp);
//         }
//         return ans;
//     }
// };

class Solution {
  public:
    vector<int> tmp;
    vector<vector<int>> ans;

    void dfs(int cur, vector<int> &nums) {
        if (cur == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[cur]);
        dfs(cur + 1, nums);
        tmp.pop_back();
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        dfs(0, nums);
        return ans;
    }
};
// @lc code=end
