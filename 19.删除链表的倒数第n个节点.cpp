/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// #include <bits/stdc++.h>
// using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *ans = new ListNode(0);
        ans->next = head;
        ListNode *p1 = ans;
        ListNode *p2 = ans;
        for (int i = 0; i < n; ++i) {
            p1 = p1->next;
        }
        while (p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return ans->next;
    }
};
// @lc code=end
