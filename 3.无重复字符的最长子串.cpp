/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
// #include <bits/stdc++.h>
// using namespace std;

class Solution {
  public:
    const int MAXN = 1e5;
    int lengthOfLongestSubstring(string s) {
        int last[128]={0};

        int n = s.length();

        int len = 0;
        int start = 0;
        for (int i = 1; i <= n; ++i) {
            int index = s[i-1];
            start = max(start, last[index] + 1);
            len = max(len, i - start + 1);
            last[index] = i;
        }
        return len;
    }
};
// @lc code=end
