// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/

// Using hash table
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  bool hasCycle(ListNode* head) {
    unordered_set<ListNode*> ss;

    ListNode* curr = head;
    while (curr) {
      if (curr == nullptr) break;
      if (ss.find(curr) != ss.end()) return true;
      ss.insert(curr);
      curr = curr->next;
    }

    return false;
  }
};

// Check if it circulate infinitely
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  bool hasCycle(ListNode* head) {
    ListNode* curr = head;

    int count = 0;
    while (curr) {
      if (curr == nullptr) break;
      if (++count > 10010) return true;

      curr = curr->next;
    }

    return false;
  }
};