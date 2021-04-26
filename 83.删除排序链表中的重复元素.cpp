/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
// #include <bits/stdc++.h>
// using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *cur = head;
        ListNode *pre = head;
        if (!head)
            return head;
        while (cur->next) {
            int tmp = cur->val;
            while (cur->next && cur->next->val == tmp) {
                cur = cur->next;
            }
            if (cur->next) {
                pre->next = cur->next;
                pre = pre->next;
                cur = pre;
            } else {
                pre->next = nullptr;
            }
        }
        return head;
    }
};
// @lc code=end
