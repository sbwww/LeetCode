/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
  public:
    int maxDepth(Node *root) {
        if (root == nullptr)
            return 0;

        queue<Node *> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                Node *node = q.front();
                q.pop();
                vector<Node *> children = node->children;
                for (auto &i : children)
                    q.push(i);

                --size;
            }
            ++ans;
        }
        return ans;
    }
};
// @lc code=end
