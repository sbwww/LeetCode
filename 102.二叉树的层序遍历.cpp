/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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

class Solution {
  public:
    queue<TreeNode *> q;
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == NULL)
            return ans;

        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            TreeNode *node;
            int n = q.size();
            while (n > 0) {
                node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                tmp.push_back(node->val);
                --n;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
// @lc code=end
