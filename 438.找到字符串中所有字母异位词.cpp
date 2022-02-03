/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
  public:
    bool equal(vector<int> &v1, vector<int> &v2) {
        for (int i = 0; i < 26; ++i) {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int len = p.size();
        if (n < len)
            return {};
        vector<int> cnt(26, 0);
        for (auto &i : p)
            ++cnt[i - 'a'];

        int left = 0;
        int right = 0;
        vector<int> window(26, 0);
        for (; right < len; ++right)
            ++window[s[right] - 'a'];

        right = len - 1;

        vector<int> ans;
        while (right < n) {
            if (equal(window, cnt)) {
            // if (window == cnt) {
                ans.emplace_back(left);
            }

            --window[s[left] - 'a'];
            ++left;
            ++right;
            if (right >= n)
                break;
            ++window[s[right] - 'a'];
        }

        return ans;
    }
};
// @lc code=end
