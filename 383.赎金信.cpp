/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        // unordered_map<char, int> mp;
        vector<int> cnt(26,0);
        for (auto &c : magazine)
            // ++mp[c];
            ++cnt[c-'a'];
        for (auto &c : ransomNote)
            // if (--mp[c] < 0)
            if (--cnt[c-'a'] < 0)
                return false;
        return true;
    }
};
// @lc code=end
