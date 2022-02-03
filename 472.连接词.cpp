/*
 * @lc app=leetcode.cn id=472 lang=cpp
 *
 * [472] 连接词
 */

// @lc code=start
struct Trie {
    bool isEnd;
    vector<Trie *> children;
    Trie() {
        this->children = vector<Trie *>(26, nullptr);
        this->isEnd = false;
    }
};

class Solution {
  public:
    Trie *trie = new Trie();

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        vector<string> ans;
        sort(words.begin(), words.end(), [&](const string &a, const string &b) {
            return a.size() < b.size();
        });

        for (auto &word : words) {
            if (word.size() == 0)
                continue;
            if (dfs(word, 0))
                ans.emplace_back(word);
            else
                insert(word);
        }
        return ans;
    }

    bool dfs(const string &word, int start) {
        if (word.size() == start)
            return true;

        Trie *node = trie;
        int n = word.size();
        for (int i = start; i < n; ++i) {
            char ch = word[i];
            int index = ch - 'a';
            node = node->children[index];
            if (node == nullptr)
                return false;

            if (node->isEnd)
                if (dfs(word, i + 1))
                    return true;
        }
        return false;
    }

    void insert(const string &word) {
        Trie *node = trie;
        for (auto &ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
                node->children[index] = new Trie();
            node = node->children[index];
        }
        node->isEnd = true;
    }
};
// @lc code=end
