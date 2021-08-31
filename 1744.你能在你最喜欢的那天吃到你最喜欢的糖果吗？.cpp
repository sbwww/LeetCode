/*
 * @lc app=leetcode.cn id=1744 lang=cpp
 *
 * [1744] 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
 */

// @lc code=start
class Solution {
private:
    using ULL = unsigned long long;

public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();

        // 前缀和
        vector<ULL> sum(n,0);
        sum[0] = candiesCount[0];

        for (int i = 1; i < n; ++i)
            sum[i] = sum[i - 1] + candiesCount[i];
        
        vector<bool> ans;
        for (auto q : queries) {
            int favoriteType = q[0];
            int favoriteDay = q[1];
            int dailyCap = q[2];

            ULL x1 = favoriteDay + 1;
            ULL y1 = (ULL)(favoriteDay + 1) * dailyCap;
            ULL x2 = (favoriteType == 0 ? 1 : sum[favoriteType - 1] + 1);
            ULL y2 = sum[favoriteType];
            
            ans.emplace_back(!(x1 > y2 || y1 < x2));
        }
        return ans;
    }
};
// @lc code=end

