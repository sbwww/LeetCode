/*
 * @lc app=leetcode.cn id=1610 lang=cpp
 *
 * [1610] 可见点的最大数目
 */

// @lc code=start
class Solution {
  public:
    int visiblePoints(vector<vector<int>> &points, int angle,
                      vector<int> &location) {
        int x = location[0];
        int y = location[1];
        vector<double> angles;
        double angle_d = (angle + 0.0) * M_PI / 180.0;
        int ans = 0;
        int flag = 0;

        for (auto &point : points)
            if (point == location)
                ++flag;
            else
                angles.emplace_back(
                    atan2(0.0 + point[1] - y, 0.0 + point[0] - x));

        sort(angles.begin(), angles.end());
        int n = angles.size();
        for (int i = 0; i < n; ++i)
            angles.emplace_back(angles[i] + 2 * M_PI);

        n = angles.size();
        int i = 0;
        int j = i;
        int cnt = 0;
        for (; j < n; ++j) {
            if (angles[j] - angles[i] > angle_d) {
                break;
            }
            ++cnt;
        }

        for (; i < n; ++i) {
            for (; j < n; ++j) {
                if (angles[j] - angles[i] > angle_d) {
                    break;
                }
                ++cnt;
            }
            ans = max(ans, cnt);
            --cnt;
        }

        return ans + flag;
    }
};
// @lc code=end
