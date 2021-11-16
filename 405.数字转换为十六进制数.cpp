/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
  public:
    vector<string> ch = {"0", "1", "2", "3", "4", "5", "6", "7",
                         "8", "9", "a", "b", "c", "d", "e", "f"};
    string toHex(int num) {
        string ans = "";
        if (num == 0)
            return "0";
        for (int i = 7; i >= 0; --i) {
            int val = (num >> (4 * i)) & 0xf;
            if (ans.length() > 0 || val > 0) {
                ans += ch[val];
            }
        }
        return ans;
    }
};
// @lc code=end
