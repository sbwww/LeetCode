/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution {
  public:
    bool checkRecord(string s) {
        int A_cnt = 0;
        int L_cnt = 0;
        for (auto &c : s) {
            if (c == 'A')
                if (++A_cnt >= 2)
                    return false;

            if (c == 'L')
            
                if (++L_cnt >= 3)
                    return false;

            if (c != 'L')
                L_cnt = 0;
        }
        return true;
    }
};
// @lc code=end
