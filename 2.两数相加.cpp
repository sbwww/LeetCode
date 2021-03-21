/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linced list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// #include <iostream>
// using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans = new ListNode(-1);
        ListNode *c = ans;
        ListNode *a = l1;
        ListNode *b = l2;
        // a+b=c
        int flag = 0; // 进位
        while (l1 != NULL || l2 != NULL) {
            int sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += flag;
            c->next = new ListNode(sum % 10);
            c = c->next;
            flag = sum / 10;
        }
        if (flag)
            c->next = new ListNode(1);
        return ans->next;
    }
};
// @lc code=end
