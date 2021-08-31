/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> ans;

  public:
    void preOrderDFS(TreeNode *cur) {
        if (!cur)
            return;

        ans.emplace_back(cur->val);
        preOrderDFS(cur->left);
        preOrderDFS(cur->right);
    }
    vector<int> preorderTraversal(TreeNode *root) {
        preOrderDFS(root);
        return ans;
    }
};
// @lc code=end
