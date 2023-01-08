// 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    int pv = -1000;
    while (curr) {
      if (curr->val != pv) {
        if (pv != -1000) {
          prev->next = curr;
        }
        pv = curr->val;
        prev = curr;
        curr = curr->next;
        prev->next = nullptr;
      } else {
        curr = curr->next;
      }
    }

    return head;
  }
};