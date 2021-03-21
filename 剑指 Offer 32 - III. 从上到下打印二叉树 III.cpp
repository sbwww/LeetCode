/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<vector<int>> ans;
    deque<TreeNode *> deq;

    void appendLeft(TreeNode *node) {
        deq.pop_front();
        if (node->left) // 先左后右
            deq.push_back(node->left);
        if (node->right)
            deq.push_back(node->right);
    }
    void appendRight(TreeNode *node) {
        deq.pop_back();
        if (node->right) // 先右后左
            deq.push_front(node->right);
        if (node->left)
            deq.push_front(node->left);
    }
    vector<vector<int>> levelOrder(TreeNode *root) {
        bool left_to_right = true;

        if (root == NULL)
            return ans;

        // 1 / 3 2 / 4 5 6 7
        deq.push_back(root);
        while (!deq.empty()) {
            int n = deq.size();
            vector<int> tmp;
            TreeNode *node;
            while (n > 0) {
                if (left_to_right) { // 先左后右
                    node = deq.front();
                    appendLeft(node);
                } else { // 先右后左
                    node = deq.back();
                    appendRight(node);
                }

                tmp.push_back(node->val);
                --n;
            }
            left_to_right ^= 1;
            ans.push_back(tmp);
        }
        return ans;
    }
};