/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

// @lc code=start
class Solution {
  public:
    string destCity(vector<vector<string>> &paths) {
        unordered_set<string> cities;
        for (auto &path : paths) {
            cities.insert(path[0]);
        }
        for (auto &path : paths) {
            if (cities.find(path[1]) == cities.end())
            
                return path[1];
        }
        return "";
    }
};
// @lc code=end
