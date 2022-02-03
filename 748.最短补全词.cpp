/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短补全词
 */

// @lc code=start
class Solution {
  public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        vector<int> cnt(26, 0);
        for (auto &c : licensePlate)
            if ('a' <= c && c <= 'z')
                ++cnt[c - 'a'];
            else if ('A' <= c && c <= 'Z')
                ++cnt[c - 'A'];

        int min_len = INT_MAX;
        string ans;
        for (auto &word : words) {
            vector<int> tmp_cnt(26, 0);
            for (auto &c : word)
                if ('a' <= c && c <= 'z')
                    ++tmp_cnt[c - 'a'];
                else if ('A' <= c && c <= 'Z')
                    ++tmp_cnt[c - 'A'];

            int i;
            for (i = 0; i < 26; ++i)
                if (cnt[i] > tmp_cnt[i])
                    break;

            if (i >= 26) {
                int len = word.size();
                if (len < min_len) {
                    ans = word;
                    min_len = len;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
