/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {
  public:
    struct TrieNode {
        vector<TrieNode *> children;
        bool isEnd;
        TrieNode() {
            children = vector<TrieNode *>(26);
            isEnd = false;
        }
    };

    void insert(TrieNode *root, string &word) {
        TrieNode *curr = root;
        for (auto c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEnd = true;
    }

    TrieNode *root;

    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) { insert(root, word); }

    bool dfs(TrieNode *curr, string word, int pos) {
        if (pos == word.size())
            return curr->isEnd;

        char ch = word[pos];
        if (ch == '.') {
            for (auto child : curr->children) {
                if (child != nullptr && dfs(child, word, pos + 1))
                    return true;
            }
        } else {
            TrieNode *child = curr->children[ch - 'a'];
            if (child != nullptr && dfs(child, word, pos + 1))
                return true;
        }
        return false;
    }

    bool search(string word) { return dfs(root, word, 0); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
