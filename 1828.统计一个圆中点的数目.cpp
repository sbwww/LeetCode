/*
 * @lc app=leetcode.cn id=1828 lang=cpp
 *
 * [1828] 统计一个圆中点的数目
 */

// @lc code=start
class Solution {
  public:
    double dist(double xc, double yc, double xp, double yp) {
        return sqrt((xc - xp) * (xc - xp) + (yc - yp) * (yc - yp));
    }
    vector<int> countPoints(vector<vector<int>> &points,
                            vector<vector<int>> &queries) {
        vector<int> ans;
        int cnt = 0;
        for (auto circle : queries) {
            double xc = circle[0];
            double yc = circle[1];
            double r = circle[2];

            for (auto point : points) {
                double xp = point[0];
                double yp = point[1];

                if (dist(xc, yc, xp, yp) <= r)
                    ++cnt;
            }
            ans.push_back(cnt);
            cnt = 0;
        }
        return ans;
    }
};
// @lc code=end
