// 82. Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    if (head == nullptr) return head;

    ListNode* ans = nullptr;
    ListNode* prev = nullptr;
    ListNode* curr = head;

    int count = 1;
    while (curr) {
      if (curr->next == nullptr || curr->next->val != curr->val) {
        if (prev != nullptr) prev->next = nullptr;
        if (count == 1) {
          if (prev == nullptr) {
            ans = prev = curr;
          } else {
            prev->next = curr;
            prev = curr;
          }
        }
        count = 1;
      } else {
        ++count;
      }
      curr = curr->next;
    }
    return ans;
  }
};