/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
  public:
    int maxProduct(vector<string> &words) {
        unordered_map<int, int> map;
        int len = words.size();
        for (int i = 0; i < len; ++i) {
            int mask = 0;
            string word = words[i];
            int word_len = word.size();
            for (int j = 0; j < word_len; ++j)
                mask |= 1 << (word[j] - 'a');

            if (map.count(mask)) {
                if (word_len > map[mask]) {
                    map[mask] = word_len;
                }
            } else {
                map[mask] = word_len;
            }
        }
        int maxProd = 0;
        for (auto &[mask1, _] : map) {
            int word_len_1 = map[mask1];
            for (auto &[mask2, _] : map) {
                if ((mask1 & mask2) == 0) {
                    int word_len_2 = map[mask2];
                    maxProd = max(maxProd, word_len_1 * word_len_2);
                }
            }
        }

        return maxProd;
    }
};
// @lc code=end
