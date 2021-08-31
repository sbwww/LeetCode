/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    vector<int> leaf1;
    vector<int> leaf2;
    void dfs(TreeNode *root, vector<int> &leaf) {
        if (!root->left && !root->right) {
            leaf.emplace_back(root->val);
            return;
        }
        if (root->left)
            dfs(root->left, leaf);
        if (root->right)
            dfs(root->right, leaf);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        dfs(root1, leaf1);
        dfs(root2, leaf2);
        return (leaf1 == leaf2);
    }
};
// @lc code=end
