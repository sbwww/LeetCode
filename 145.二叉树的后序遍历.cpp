/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    void postOrderDFS(TreeNode *cur) {
        if (!cur)
            return;

        postOrderDFS(cur->left);
        postOrderDFS(cur->right);
        ans.emplace_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        postOrderDFS(root);
        return ans;
    }
};
// @lc code=end
