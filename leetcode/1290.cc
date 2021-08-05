//
// 1290. Convert Binary Number in a Linked List to Integer
// Problem: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
//

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
    int getDecimalValue(ListNode* head) {
        vector<bool> bins;
        ListNode* curr = head;
        while (curr != nullptr) {
            bins.push_back(curr->val);
            curr = curr->next;
        }
        int mult = 1;
        int ans = 0;
        for (auto it = bins.rbegin(); it != bins.rend(); it++) {
            ans += (*it) * mult;
            mult *= 2;
        }
        return ans;
    }
};