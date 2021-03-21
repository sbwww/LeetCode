/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
// #include <bits/stdc++.h>
// using namespace std;

// // Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
// [2147483647]
// [1,1]
class Solution {
  public:
    bool dfs(TreeNode *root, long long Min, long long Max) {
        if (root == NULL)
            return true;
        if (root->val <= Min || root->val >= Max)
            return false;
        return dfs(root->left, Min, root->val) &&
               dfs(root->right, root->val, Max);
    }
    bool isValidBST(TreeNode *root) {
        return dfs(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    }
};
// @lc code=end
