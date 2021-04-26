/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    int ans = 1e5 + 1;
    int pre = -1;
    void dfs(TreeNode *root) {
        if (root == nullptr)
            return;

        dfs(root->left);
        if (pre == -1) {
            pre = root->val;
        } else {
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        dfs(root->right);
    }

    int getMinimumDifference(TreeNode *root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end
