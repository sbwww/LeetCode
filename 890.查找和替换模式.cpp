/*
 * @lc app=leetcode.cn id=890 lang=cpp
 *
 * [890] 查找和替换模式
 */

// @lc code=start
class Solution {
  public:
    bool match(string word, string pattern) {
        vector<int> index1(26, -1);
        vector<int> index2(26, -1);
        for (int i = 0; i < word.size(); ++i) {
            char w = word[i] - 'a';
            char p = pattern[i] - 'a';
            if (index1[w] != index2[p])
                return false;
            index1[w] = index2[p] = i;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string> &words,
                                         string pattern) {
        vector<string> ans;
        for (auto word : words)
            if (match(word, pattern))
                ans.push_back(word);
        return ans;
    }
};
// @lc code=end
// ["aaa"], "abb" 返回 []
