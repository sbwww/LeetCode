/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
  public:
    bool backspaceCompare(string S, string T) {
        string S1, T1;
        for (auto c : S) {
            if (c != '#')
                S1.push_back(c);
            else if (!S1.empty())
                S1.pop_back();
        }
        for (auto c : T) {
            if (c != '#')
                T1.push_back(c);
            else if (!T1.empty())
                T1.pop_back();
        }
        return S1 == T1;
        // "ab##"
        // "c#d#"
    }
};
// @lc code=end
