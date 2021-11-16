/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 */

// @lc code=start
class Solution {
  public:
    // 不同的 needs 所需的价格
    map<vector<int>, int> _cache;

    int dfs(vector<int> needs, vector<int> &price,
            vector<vector<int>> &special) {

        if (_cache[needs]) // 已计算过，直接返回
            return _cache[needs];

        int ans = 0;
        // 全单买
        for (int i = 0; i < needs.size(); ++i)
            ans += needs[i] * price[i];

        // 遍历每个礼包，购买它，看看是不是能获得更便宜的价格
        for (int i = 0; i < special.size(); ++i) {
            vector<int> next = needs;
            bool valid = true;

            // 跳过礼包中商品数量超过需求的
            for (int item = 0; item < price.size(); ++item) {
                if (special[i][item] > needs[item]) {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                continue;

            // 礼包符合要求，用 next 数组记录买过大礼包之后还需要买多少商品
            for (int item = 0; item < price.size(); ++item)
                next[item] -= special[i][item];

            ans = min(ans, dfs(next, price, special) + special[i].back());
        }

        // 更新cache
        _cache[needs] = ans;
        return ans;
    }

    int shoppingOffers(vector<int> &price, vector<vector<int>> &special,
                       vector<int> &needs) {
        return dfs(needs, price, special);
    }
};
// @lc code=end
