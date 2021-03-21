/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left == right)
            return head;
        if (head->next == NULL)
            return head;
        if (left == 1 && right == 2) {
            ListNode *head_next = head->next;
            head->next = head_next->next;
            head_next->next = head;
            return head_next;
        }
        if (head->next->next == NULL) {
            return head;
        }
        ListNode *start = new ListNode(-1);
        start->next = head;
        ListNode *pre = start;
        ListNode *cur = start;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
            cur = cur->next;
        }
        cur = cur->next;
        ListNode *next;
        for (int i = left; i < right; ++i) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return start->next;
    }
};
// @lc code=end