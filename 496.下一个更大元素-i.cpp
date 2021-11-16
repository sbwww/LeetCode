/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
  public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int> mp;
        stack<int> stk;

        vector<int> ans(n1, -1);

        for (int i = 0; i < n1; ++i) {
            mp.insert(make_pair(nums1[i], i));
        }

        for (auto &i : nums2) {
            while (!stk.empty() && stk.top() < i) {
                ans[mp[stk.top()]] = i;
                stk.pop();
            }
            if (mp.find(i) != mp.end()) {
                stk.push(i);
            }
        }
        // while (!stk.empty()) {
        //     ans[mp[stk.top()]] = -1;
        //     stk.pop();
        // }

        return ans;
    }
};
// @lc code=end
