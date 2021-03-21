/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
// #include <bits/stdc++.h>
// using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
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
    ListNode *getMid(ListNode *left, ListNode *right) {
        ListNode *p1 = left;
        ListNode *p2 = left;
        while (p2 != right && p2->next != right) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }

    TreeNode *getTree(ListNode *left, ListNode *right) {
        if (left == right)
            return NULL;
        ListNode *listMid = getMid(left, right);
        TreeNode *treeRoot = new TreeNode(listMid->val);
        treeRoot->left = getTree(left, listMid);
        treeRoot->right = getTree(listMid->next, right);
        return treeRoot;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        return getTree(head, NULL);
    }
};
// @lc code=end
