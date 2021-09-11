// Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/

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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    ListNode *head, *a, *b;
    if (l1->val <= l2->val) {
      head = a = l1;
      b = l2;
    } else {
      head = a = l2;
      b = l1;
    }

    while (b && a->next) {
      if (a->next->val > b->val) {
        ListNode* tmp = a->next;
        a->next = b;
        b = tmp;
      }
      a = a->next;
    }
    if (b) a->next = b;

    return head;
  }
};