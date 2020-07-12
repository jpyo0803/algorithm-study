//
// 듣보잡
// problem: https://www.acmicpc.net/problem/1764
//

#include <cstdio>
#include <string>

#define RED false
#define BLACK true

typedef bool Color;

using namespace std;

struct Node {
  Node(const string &x) : key(x) {
    parent = left = right = nullptr;
    color = RED;
  }
  string key;
  Node *parent, *left, *right;
  Color color;
};

int N, M;

bool IsBigger(const string& x, const string& y) {
  int i = 0;
  while (i < x.length() && i < y.length()) {
    if (x[i] > y[i]) {
      return true;
    } else if (x[i] < y[i]){
      return false;
    }
    i++;
  }
  return x.length() > y.length();
}

class RedBlackTree {
 public:
  void Insert(Node* new_node) {
    num_node_ += 1;
    Node* previous_node = nullptr;
    Node* current_node = root_node_;
    while (current_node != nullptr) {
      previous_node = current_node;
      if (IsBigger(new_node->key, current_node->key)) {
        current_node = current_node->right;
      } else {
        current_node = current_node->left;
      }
    }
    new_node->parent = previous_node;
    if (previous_node == nullptr) {
      root_node_ = new_node;
    } else if (IsBigger(new_node->key, previous_node->key)) {
      previous_node->right = new_node;
    } else {
      previous_node->left = new_node;
    }
    FixUp(new_node);
  }

  Node* Search(const string& target_key) {
    Node* current_node = root_node_;
    while (!(current_node == nullptr || target_key == current_node->key)) {
      if (IsBigger(target_key, current_node->key)) {
        current_node = current_node->right;
      } else {
        current_node = current_node->left;
      }
    }
    return current_node;
  }

  int num_node() const {
    return num_node_;
  }

  Node* get_root() const {
    return root_node_;
  }

  void InOrderTraversal() {
    InOrderTraversalRecursive(root_node_);
  }
 private:
  void RotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) { // if x was root
      root_node_ = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  void RotateRight(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != nullptr) {
      x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == nullptr) {
      root_node_ = x;
    } else if (y == y->parent->left) {
      y->parent->left = x;
    } else {
      y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
  }

  void FixUp(Node* z) {
    while (z != root_node_ && z->color != BLACK && z->parent->color == RED) {
      if (z->parent == z->parent->parent->left) {
        Node* y = z->parent->parent->right;
        if (y != nullptr && y->color == RED) { // Case 1
          z->parent->color = y->color = BLACK;
          z->parent->parent->color = RED;
          z = z->parent->parent;
        } else {
          if (z == z->parent->right) {
            z = z->parent;
            RotateLeft(z);
          } else {
            Color tmp = z->parent->color;
            z->parent->color = z->parent->parent->color;
            z->parent->parent->color = tmp;
            z = z->parent->parent;
            RotateRight(z);
          }
        }
      } else {
        Node* y = z->parent->parent->left;
        if (y != nullptr && y->color == RED) { // Case 1
          z->parent->color = y->color = BLACK;
          z->parent->parent->color = RED;
          z = z->parent->parent;
        } else {
          if (z == z->parent->left) {
            z = z->parent;
            RotateRight(z);
          } else {
            Color tmp = z->parent->color;
            z->parent->color = z->parent->parent->color;
            z->parent->parent->color = tmp;
            z = z->parent->parent;
            RotateLeft(z);
          }
        }
      }
    }
    root_node_->color = BLACK;
  }

  void InOrderTraversalRecursive(Node* current_node) {
    if (current_node != nullptr) {
      InOrderTraversalRecursive(current_node->left);
      printf("%s\n", (current_node->key).c_str());
      InOrderTraversalRecursive(current_node->right);
    }
  }

  int num_node_ = 0;
  Node* root_node_ = nullptr;
};

char input[21];
string input2str;

int main() {
  scanf("%d%d", &N, &M);

  RedBlackTree rb_tree;
  RedBlackTree rb_tree_ans;
  for (int i = 0; i < N; i++) {
    scanf("%s", input);
    input2str = input;
    Node* tmp = new Node(input2str);
    rb_tree.Insert(tmp);
  }

  for (int i = 0; i < M; i++) {
    scanf("%s", input);
    Node* ret_node = rb_tree.Search(input);
    if (ret_node != nullptr) {
      Node* tmp = new Node(ret_node->key);
      rb_tree_ans.Insert(tmp);
    }
  }

  printf("%d\n", rb_tree_ans.num_node());
  rb_tree_ans.InOrderTraversal();
  return 0;
}



