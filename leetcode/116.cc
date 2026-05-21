// 116. Populating Next Right Pointers in Each Node
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

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

// My Initial Solution
class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return root;

    vector<Node*> node_arr;
    queue<Node*> que;
    que.push(root);

    while (!que.empty()) {
      Node* x = que.front();
      que.pop();
      node_arr.push_back(x);
      if (x->left) que.push(x->left);
      if (x->right) que.push(x->right);
    }

    int y = 1, sy = 0;
    for (int i = 0; i < node_arr.size() - 1; ++i) {
      if (i == sy) {
        y *= 2;
        sy += y;
      } else {
        node_arr[i]->next = node_arr[i + 1];
      }
    }

    return root;
  }
};