/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
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
class Solution {
  public:
    ListNode *head;
    int size;
    Solution(ListNode *head) {
        this->head = head;
        this->size = 0;
        ListNode *cur = head;
        while (cur) {
            cur = cur->next;
            ++this->size;
        }
        srand(time(NULL));
    }

    int getRandom() {
        ListNode *cur = this->head;
        int cnt = this->size;
        while (cur->next) {
            if (((double)rand() / (RAND_MAX)) < (double)(1.0 / cnt))
                return cur->val;
            cur = cur->next;
            --cnt;
        }
        return cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end
