/*
 * @lc app=leetcode.cn id=1829 lang=cpp
 *
 * [1829] 每个查询的最大异或值
 */

// @lc code=start
class Solution {
  public:
    stack<int> s;

    int getK(int xorValue, int maximumBit) {
        int ans = 0;
        int weight = 1;
        for (int i = 0; i < maximumBit; ++i) {
            int low_bit = xorValue & 1;
            if (low_bit == 0) {
                ans += weight;
            }
            weight <<= 1;
            xorValue >>= 1;
        }
        return ans;
    }

    vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
        vector<int> ans;
        int xorValue = 0;
        for (auto i : nums) {
            xorValue ^= i;
            s.push(getK(xorValue, maximumBit));
            // cout<<xorValue<<" "<<s.top()<<endl;
        }
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
// @lc code=end
