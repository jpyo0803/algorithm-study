// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int idx = 0;
    ListNode* now = head;
    while (now) {
      ++idx;
      now = now->next;
    }

    int tidx = idx - n;

    ListNode* prev = nullptr;
    now = head;
    while (tidx > 0) {
      prev = now;
      now = now->next;
      --tidx;
    }

    if (prev)
      prev->next = now->next;
    else
      head = now->next;

    return head;
  }
};