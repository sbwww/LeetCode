/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
    queue<pair<TreeNode *, int>> q;

    bool bfs(int tar1, int tar2) {
        int depth = -1;
        int parent = -1;
        while (!q.empty()) {
            if (q.front().first->left) {
                if (q.front().first->left->val == tar1 ||
                    q.front().first->left->val == tar2) {
                    if (parent == q.front().first->val)
                        return false;
                    if (depth == -1)
                        depth = q.front().second;
                    else if (depth == q.front().second)
                        return true;
                    else
                        return false;
                    parent = q.front().first->val;
                } else {
                    q.push({q.front().first->left, q.front().second + 1});
                }
            }
            if (q.front().first->right) {
                if (q.front().first->right->val == tar1 ||
                    q.front().first->right->val == tar2) {
                    if (parent == q.front().first->val)
                        return false;
                    if (depth == -1)
                        depth = q.front().second;
                    else if (depth == q.front().second)
                        return true;
                    else
                        return false;
                    parent = q.front().first->val;
                } else {
                    q.push({q.front().first->right, q.front().second + 1});
                }
            }
            q.pop();
        }
        return false;
    }
    bool isCousins(TreeNode *root, int x, int y) {
        q.push({root, 0});
        return bfs(x, y);
    }
};
// @lc code=end
