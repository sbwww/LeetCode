/*
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 */

// @lc code=start
class Solution {
  public:
    string originalDigits(string s) {
        unordered_map<char, int> mp;
        for (auto &c : s)
            ++mp[c];

        vector<int> cnt(10);
        cnt[0] = mp['z']; // zero
        cnt[2] = mp['w']; // two
        cnt[4] = mp['u']; // four
        cnt[6] = mp['x']; // six
        cnt[8] = mp['g']; // eight

        cnt[3] = mp['h'] - cnt[8]; // three 除了 eight 的 h
        cnt[5] = mp['f'] - cnt[4]; // five 除了 four 的 f
        cnt[7] = mp['s'] - cnt[6]; // seven 除了 six 的 s

        // one 除了 zero two four 的 o
        cnt[1] = mp['o'] - cnt[0] - cnt[2] - cnt[4];
        // nine 除了 five six eight 的 i
        cnt[9] = mp['i'] - cnt[5] - cnt[6] - cnt[8];

        string ans;
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < cnt[i]; ++j)
                ans += char(i + '0');

        return ans;
    }
};
// @lc code=end
