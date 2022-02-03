/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start
class Solution {
  public:
    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(), courses.end(),
             [](const auto &a, const auto &b) { return a[1] < b[1]; });
        priority_queue<int> pq;
        int cur = 0;
        for (const auto &course : courses) {
            int duration = course[0];
            int lastDay = course[1];
            if (cur + duration <= lastDay) {
                cur += duration;
                pq.push(duration);
            } else if (!pq.empty() && pq.top() > duration) {
                cur -= (pq.top() - duration);
                pq.pop();
                pq.push(duration);
            }
        }
        return pq.size();
    }
};
// @lc code=end
