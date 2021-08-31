/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
    int ans;
    int low, high;

  public:
    void dfs(TreeNode *root) {
        if (root == nullptr)
            return;

        if (root->val < low)
            dfs(root->right);
        else if (root->val > high)
            dfs(root->left);
        else {
            ans += root->val;
            dfs(root->left);
            dfs(root->right);
        }
    }
    int rangeSumBST(TreeNode *root, int low, int high) {
        this->low = low;
        this->high = high;
        dfs(root);
        return ans;
    }
};
// @lc code=end
