/*
 * @lc app=leetcode.cn id=1442 lang=cpp
 *
 * [1442] 形成两个异或相等数组的三元组数目
 */

// @lc code=start
class Solution {
  public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();

        if (n == 1)
            return 0;

        int cnt = 0;

        vector<int> preSum;
        preSum.emplace_back(0);

        for (auto i : arr) {
            preSum.emplace_back(i ^ preSum.back());
        }

        // a^b=b^c
        // 两边同^b
        // a^b^b=b^c^b，两个b消掉
        // a=c
        for (int i = 1; i <= n; ++i) {
            for (int k = i; k <= n; ++k) {
                if (preSum[k] == preSum[i - 1])
                    cnt += k - i;
            }
        }
        return cnt;
    }
};
// @lc code=end
