/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
  public:
    string solve(string s) {
        char tmp = s[0];
        int cnt = 0;
        string ans = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == tmp) {
                ++cnt;
            } else {
                ans += to_string(cnt);
                ans.push_back(tmp);
                tmp = s[i];
                cnt = 1;
            }
        }
        ans += to_string(cnt);
        ans.push_back(tmp);
        return ans;
    }
    string countAndSay(int n) {
        string last = "1";
        for (int i = 1; i < n; ++i) {
            last = solve(last);
        }
        return last;
    }
};
// @lc code=end
