/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
// #include <bits/stdc++.h>
// using namespace std;
// //  Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
// [1,2,2,2,null,2]
// [5,4,1,null,1,null,4,2,null,2,null]

class Solution {
  public:
    vector<int> inOrder;
    void Traverse(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            inOrder.push_back(root->val);
            return;
        }
        if (root->left == NULL && root->right != NULL) {
            inOrder.push_back(-1);
            inOrder.push_back(root->val);
            Traverse(root->right);
            return;
        }
        if (root->left != NULL && root->right == NULL) {
            Traverse(root->left);
            inOrder.push_back(root->val);
            inOrder.push_back(-1);
            return;
        }
        Traverse(root->left);
        inOrder.push_back(root->val);
        Traverse(root->right);
    }
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        if (root->left == NULL && root->right == NULL)
            return true;
        if ((root->left == NULL && root->right != NULL) ||
            (root->left != NULL && root->right == NULL) ||
            (root->left->val != root->right->val))
            return false;
        Traverse(root);
        int len = inOrder.size();
        // cout << len << endl;
        // for (auto i : inOrder) {
        //     cout << i << " ";
        // }
        if (len == 0)
            return true;
        if (!(len & 1))
            return false;
        for (int i = 0; i < len / 2; ++i) {
            if (inOrder[i] != inOrder[len - i - 1])
                return false;
        }
        return true;
    }
};
// @lc code=end
