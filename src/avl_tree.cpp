#include <iostream>
#include <cmath>
using namespace std;

class Node {
public:
  int key;
  int height;
  Node *left, *right, *parent;
};

Node* newNode(int _key) {
  Node* tmp = new Node();
  tmp->key = _key;
  tmp->left = tmp->right = tmp->parent = nullptr;
  tmp->height = 1;
  return tmp;
}

int height(Node* N) {
  if (N == nullptr) return 0;
  return N->height;
}

int get_balance(Node* N) {
  if (N == nullptr) {
    return 0;
  } 
  return height(N->left) - height(N->right);
}

int max(int a, int b) {
  return (a > b ? a : b);
}
Node* left_rotate(Node* x) {
  Node* y = x->right;
  Node* y_l = y->left;

  x->right = y_l;
  y->left = x;
  x->height = max(height(x->right), height(x->left)) + 1;
  y->height = max(height(y->right), height(y->left)) + 1;
  return y;
}

Node* right_rotate(Node* y) {
  Node* x = y->left;
  Node* x_r = x->right;

  y->left = x_r;
  x->right = y;
  x->height = max(height(x->right), height(x->left)) + 1;
  y->height = max(height(y->right), height(y->left)) + 1;
  return x;
}

Node* insert(Node* node, int key) {
  if (node == nullptr) {
    return newNode(key);
  }

  if (node->key < key) {
    node->right = insert(node->right, key);
  } else if (node->key > key) {
    node->left = insert(node->left, key);
  } else {
    return node;
  }

  node->height = max(height(node->left), height(node->right)) + 1;

  int balance = get_balance(node);

  if (balance > 1) {
    int balance2 = get_balance(node->right);
    if (balance < -1) {
      left_rotate(node->right);
    }
    return right_rotate(node);

  } else if (balance < -1) {
    int balance2 = get_balance(node->left);
    if (balance2 > 1) {
      right_rotate(node->left);
    }
    return left_rotate(node);
  }
  return node;
}

int search(Node* curr, int key, int depth) {
  if (curr != nullptr) {
    if (curr->key < key) {
      return search(curr->right, key, depth + 1);
    } else if (curr->key > key) {
      return search(curr->left, key, depth + 1);
    } else {
      return depth + 1;
    }
  }
}

void traverse(Node* n) {
  if (n != nullptr) {
    traverse(n->left);
    cout << n->key << " / " << n->height << "\n";
    traverse(n->right);
  }
}

int main() {
  int n = 15;
  Node* root = nullptr;
  for (int i = 1; i <= n; i++) {
    root = insert(root, i);
  }

  traverse(root);
/*
  int max_depth = 0;
  for (int i = 1; i <= n; i++) {
    int depth = search(root, i, 0);
    if (depth > max_depth) max_depth = depth;
    cout << "search "<< i << " : " << depth << "\n";
  }
  cout << "max depth = " << max_depth << "\n";
  */
  return 0;
}