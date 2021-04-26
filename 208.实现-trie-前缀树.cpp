/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
  public:
    bool isEnd;
    Trie *next[26];

    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for (auto c : word) {
            int tmp_c = c - 'a';
            if (node->next[tmp_c] == NULL)
                node->next[tmp_c] = new Trie();

            node = node->next[tmp_c];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for (auto c : word) {
            node = node->next[c - 'a'];
            if (node == NULL)
                return false;
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for (auto c : prefix) {
            node = node->next[c - 'a'];
            if (node == NULL)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
