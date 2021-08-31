/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @lc code=start
class Solution {
  public:
    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<int, int> cnt;
        for (auto &row : wall) {
            int n = row.size();
            int sum = 0;
            for (int i = 0; i < n - 1; ++i) {
                sum += row[i];
                ++cnt[sum];
            }
        }
        int maxCnt = 0;
        for (auto item : cnt) {
            maxCnt = max(maxCnt, item.second);
        }
        return wall.size() - maxCnt;
    }
};
/*

1 2 2 1
3 1 2
1 3 2
2 4
3 1 2
1 3 1 1

1 0 1 0 1
0 0 1 1 0
1 0 0 1 0
0 1 0 0 0
0 0 1 1 0
1 0 0 1 1

*/
// @lc code=end
