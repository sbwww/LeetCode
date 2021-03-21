/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
// #include <bits/stdc++.h>
// using namespace std;
// //  Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right)
//         : val(x), left(left), right(right) {}
// };

class Solution {
  public:
    bool check(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) {
            return true;
        } else if (p != NULL && q != NULL) {
            if (p->val == q->val) {
                return check(p->left, q->left) && check(p->right, q->right);
            }
            return false;
        }
        return false;
    }
    bool isSameTree(TreeNode *p, TreeNode *q) { return check(p, q); }
};
// @lc code=end
