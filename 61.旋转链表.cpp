/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 || (!head) || (!head->next))
            return head;
        ListNode *p1 = new ListNode(-101, head);
        ListNode *p2 = head;
        int len = 0;
        while (p1->next != nullptr) {
            p1 = p1->next;
            ++len;
        }
        k %= len;

        if (k == 0)
            return head;

        p1->next = head;
        int diff = len - k;
        for (int i = 1; i <= diff - 1; ++i) {
            p2 = p2->next;
        }
        ListNode *p3 = p2->next;
        p2->next = NULL;

        return p3;
    }
};
// @lc code=end
