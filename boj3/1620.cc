//
// I am the Pokemon master Lee dasom
// Problem: https://www.acmicpc.net/problem/1620
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<string> names;
char input[22];
int N, M;

struct Node {
  Node(const string &name, int order) : name_{name}, order_{order} {}
  string name_;
  int order_, height_{0};
  Node *left_{nullptr}, *right_{nullptr};
};

int Max(int x, int y);
bool IsBigger(string &x, string &y);
int GetBalance(Node *node);
int GetHeight(Node *node);

Node *RotateLeft(Node *x) {
  Node *y = x->right_;
  x->right_ = y->left_;
  y->left_ = x;
  x->height_ = Max(GetHeight(x->left_), GetHeight(x->right_)) + 1;
  y->height_ = Max(GetHeight(y->left_), GetHeight(y->right_)) + 1;
  return y;
}

Node *RotateRight(Node *y) {
  Node *x = y->left_;
  y->left_ = x->right_;
  x->right_ = y;
  y->height_ = Max(GetHeight(y->left_), GetHeight(y->right_)) + 1;
  x->height_ = Max(GetHeight(x->left_), GetHeight(x->right_)) + 1;
  return x;
}

Node *Insert(Node *current_node, Node *new_node) {
  if (current_node == nullptr) {
    return new_node;
  }

  if (IsBigger(new_node->name_, current_node->name_)) {
    current_node->right_ = Insert(current_node->right_, new_node);
  } else {
    current_node->left_ = Insert(current_node->left_, new_node);
  }

  current_node->height_ = Max(GetHeight(current_node->left_), GetHeight(current_node->right_)) + 1;

  int balance = GetBalance(current_node);

  if (balance > 1) {
    if (GetBalance(current_node->left_) < 0) {
      current_node->left_ = RotateLeft(current_node->left_);
    }
    current_node = RotateRight(current_node);
  } else if (balance < -1) {
    if (GetBalance(current_node->right_) > 0) {
      current_node->right_ = RotateRight(current_node->right_);
    }
    current_node = RotateLeft(current_node);
  }
  return current_node;
}

int Search(Node *current_node, string &name) {
  if (current_node->name_ == name) {
    return current_node->order_;
  }

  if (IsBigger(name, current_node->name_)) {
    return Search(current_node->right_, name);
  } else {
    return Search(current_node->left_, name);
  }
}

int main() {
  scanf("%d%d", &N, &M);

  bool first = true;
  Node *root;
  for (int i = 1; i <= N; i++) {
    scanf("%s", input);
    string name = input;
    names.push_back(name);
    Node *tmp = new Node(name, i);
    if (first) {
      first = false;
      root = tmp;
    } else {
      root = Insert(root, tmp);
    }
  }

  for (int i = 0; i < M; i++) {
    scanf("%s", input);
    string request = input;
    int number = atoi(input);
    if (number == 0) {
      printf("%d\n", Search(root, request));
    } else {
      printf("%s\n",  names[number - 1].c_str());
    }
  }
  return 0;
}

int Max(int x, int y) { return x > y ? x : y; }

bool IsBigger(string &x, string &y) {
  int idx = 0;
  while (idx < x.length() && idx < y.length()) {
    if (x[idx] < y[idx]) {
      return false;
    } else if (x[idx] > y[idx]) {
      return true;
    }
    idx += 1;
  }
  return x.length() > y.length();
}

int GetBalance(Node *node) {
  if (node == nullptr) return 0;
  return GetHeight(node->left_) - GetHeight(node->right_);
}

int GetHeight(Node *node) {
  if (node == nullptr) return 0;
  return node->height_;
}