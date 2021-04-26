/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
    TreeNode *cur;

  public:
    void dfs(TreeNode *root) {
        if (root->left != nullptr)
            dfs(root->left);

        cur->right = root;
        root->left = nullptr;
        cur = root;

        if (root->right != nullptr)
            dfs(root->right);
    }
    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *head = new TreeNode();
        cur = head;
        dfs(root);
        return head->right;
    }
};
// @lc code=end
