/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 */

// @lc code=start
class Solution {
  public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> week = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                               "Friday", "Saturday", "Sunday"};
        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        int days = 365 * (year - 1971) + (year - 1969) / 4;
        for (int i = 0; i < month - 1; ++i)
            days += monthDays[i];

        if (month > 3)
            days += (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));

        days += day;
        // 1971.1.1 Friday
        return week[(days + 3) % 7];
    }
};
// @lc code=end
