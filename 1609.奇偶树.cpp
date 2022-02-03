/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] 奇偶树
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
    bool isEvenOddTree(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            int prev = level & 1 ? INT_MAX : INT_MIN;
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                int value = node->val;
                if (level % 2 == value % 2)
                    return false;

                if ((level % 2 == 0 && value <= prev) ||
                    (level % 2 == 1 && value >= prev))
                    return false;

                prev = value;
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            ++level;
        }
        return true;
    }
};
// @lc code=end
