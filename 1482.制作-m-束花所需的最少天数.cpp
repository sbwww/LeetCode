/*
 * @lc app=leetcode.cn id=1482 lang=cpp
 *
 * [1482] 制作 m 束花所需的最少天数
 */

// @lc code=start
class Solution {
    vector<int> bloomDay;
    int m;
    int k;
    int n;

  public:
    bool check(int day) {
        int cnt = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (bloomDay[i] <= day) {
                ++cnt;
                res += cnt / k;
                cnt %= k;
            } else {
                cnt = 0;
            }
        }
        return res >= m;
    }
    int minDays(vector<int> &bloomDay, int m, int k) {
        n = bloomDay.size();
        if (m * k > n)
            return -1;

        this->bloomDay = bloomDay;
        this->m = m;
        this->k = k;

        int left = INT_MAX;
        int right = 0;
        for (auto i : bloomDay) {
            left = min(i, left);
            right = max(i, right);
        }

        while (left < right) {
            int mid = (left + right) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return check(left) ? left : -1;
    }
};
// @lc code=end
