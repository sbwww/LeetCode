/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    void dfs(TreeNode *curr, bool flag) {
        if (curr == nullptr || flag == false)
            return;
        dfs(curr->left, flag);
        pq.push(curr->val);
        if (pq.size() > k) {
            flag = false;
            return;
        }
        dfs(curr->right, flag);
    }
    int kthSmallest(TreeNode *root, int k) {
        this->k = k;
        dfs(root, true);
        int cnt = 0;
        while (!pq.empty()) {
            if (++cnt == k)
                break;
            pq.pop();
        }
        return pq.top();
    }
};
// @lc code=end
