/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
// #include <bits/stdc++.h>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
// [1,2,2,3,3,null,null,4,4]
class Solution {
  public:
    int dfs(TreeNode *cur) {
        if (cur == NULL) {
            return 0;
        }
        int depthLeft = dfs(cur->left);
        if (depthLeft == -1) {
            return -1;
        }
        int depthRight = dfs(cur->right);
        if (depthRight == -1) {
            return -1;
        }
        if (abs(depthLeft - depthRight) > 1) {
            return -1;
        }
        return max(depthLeft, depthRight) + 1;
    }
    bool isBalanced(TreeNode *root) {
        int depth = dfs(root);
        if (depth == -1)
            return false;
        return true;
    }
};
// @lc code=end
