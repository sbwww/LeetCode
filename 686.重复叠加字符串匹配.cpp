/*
 * @lc app=leetcode.cn id=686 lang=cpp
 *
 * [686] 重复叠加字符串匹配
 */

// @lc code=start
class Solution {
  public:
    int strStr(string &haystack, string &needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0)
            return 0;

        vector<int> pi(m); // 真前缀==真后缀的最大长度表
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && needle[i] != needle[j])
                j = pi[j - 1];

            if (needle[i] == needle[j])
                ++j;

            pi[i] = j;
        }
        for (int i = 0, j = 0; i - j < n; ++i) {
            // b 开始匹配的位置是否超过第一个叠加的 a
            while (j > 0 && haystack[i % n] != needle[j])
                // haystack 是循环叠加的字符串，所以取 i % n
                j = pi[j - 1];

            if (haystack[i % n] == needle[j])
                ++j;

            if (j == m)
                return i - m + 1;
        }
        return -1;
    }

    int repeatedStringMatch(string a, string b) {
        int an = a.size();
        int bn = b.size();

        int index = strStr(a, b);
        if (index == -1)
            return -1;

        if (an - index >= bn)
            return 1;

        return (bn + index - an - 1) / an + 2;
    }
};
// @lc code=end
