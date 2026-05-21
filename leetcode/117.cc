// 117. Populating Next Right Pointers in Each Node II
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
 public:
  Node* connect(Node* root) {
    vector<Node*> frontier, next;
    frontier.push_back(root);
    while (!frontier.empty()) {
      for (int i = 0; i < frontier.size(); ++i) {
        if (frontier[i] == nullptr) continue;
        if (i > 0) {
          if (frontier[i - 1] != nullptr) {
            frontier[i - 1]->next = frontier[i];
          }
        }
        if (frontier[i]->left) next.push_back(frontier[i]->left);
        if (frontier[i]->right) next.push_back(frontier[i]->right);
      }
      frontier.swap(next);
      next.clear();
    }
    return root;
  }
};