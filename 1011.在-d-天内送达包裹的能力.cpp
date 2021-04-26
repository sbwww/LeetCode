/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
  public:
    int solve(int ship, vector<int> &weights) {
        int cur = 0;
        int day = 0;
        for (auto w : weights) {
            if (cur + w <= ship) {
                cur += w;
            } else {
                ++day;
                cur = w;
            }
        }
        ++day;
        return day;
    }

    int shipWithinDays(vector<int> &weights, int D) {
        int left = 0;
        int right = 0;
        int n = weights.size();
        for (auto w : weights) {
            left = max(left, w);
            right += w;
        }
        while (left <= right) {
            // cout << left << " ~ " << right << endl;
            int mid = (left + right) / 2;
            int tmp_day = solve(mid, weights);
            // cout << mid << " " << tmp_day << endl;
            if (tmp_day > D) {
                left = mid + 1;
            } else if (tmp_day <= D) {
                right = mid - 1;
            }
        }

        return left;
    }
};
// [3,2,2,4,1,4]\n3
// @lc code=end
