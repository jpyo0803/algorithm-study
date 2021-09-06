// 876. Middle of the Linked List
// https://leetcode.com/problems/middle-of-the-linked-list/

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
  ListNode* middleNode(ListNode* head) {
    ListNode* now = head;

    int idx = 0;
    while (now) {
      ++idx;
      now = now->next;
    }

    int tidx = idx / 2;
    now = head;
    while (tidx > 0) {
      now = now->next;
      --tidx;
    }
    return now;
  }
};