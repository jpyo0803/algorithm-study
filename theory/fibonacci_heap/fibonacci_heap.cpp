#include "fibonacci_heap.h"

#include <cmath>

FibonacciHeap::FibonacciHeap(int64_t v)  // v = max possible # of elements
    : min_node_(nullptr),
      root_(nullptr),
      num_trees_(0),
      size_(0),
      node_ptr_vec_(v + 10, nullptr) {}

void FibonacciHeap::Insert(int64_t new_key, int64_t new_value) {
  // Create a new node with key and value
  Node *new_node = CreateNode();
  // Newly created node's left and right must point itself
  assert(new_node->left == new_node && new_node->right == new_node);

  new_node->key = new_key;
  new_node->value = new_value;

  // register newly created node for O(1) locating
  node_ptr_vec_.at(new_value) = new_node;

  if (root_ == nullptr) {
    root_ = new_node;
  } else {
    AddListXToListY(new_node, root_);
  }

  // Update min_node if necessary
  UpdateMin(new_node);
  // increase # of trees
  num_trees_++;
  size_++;
}

std::pair<int64_t, int64_t> FibonacciHeap::ExtractMin() {
  assert(root_ != nullptr);
  assert(min_node_ != nullptr);
  assert(num_trees_ >= 1);
  assert(size_ >= 1);

  auto ret_val = std::make_pair(min_node_->key, min_node_->value);

  // first detach min node from root list
  // let's copy min_node in case of losing
  assert(root_ != nullptr);
  DetachNodeFromRootList(min_node_);
  if (min_node_->child != nullptr) {
    num_trees_ += min_node_->degree;
    // make children all point nothing, rootlist
    Node *curr = min_node_->child;
    Node *head = min_node_->child;
    do {
      curr->parent = nullptr;
      curr = curr->right;
    } while (curr != head);

    if (root_ == nullptr) {
      // detached min node was the last node in rootlist
      root_ = min_node_->child;
    } else {
      AddListXToListY(min_node_->child, root_);
    }
  }
  // ready to consolidate
  // Consolidation only makes sense when num_trees >= 2
  if (num_trees_ >= 2) {
    std::size_t deg_arr_sz =
        static_cast<std::size_t>(std::log2(size_ * 3));  // VERIFY THIS
    std::vector<Node *> deg_arr(deg_arr_sz, nullptr);

    {
      // do consolidation
      // root might change dynamically
      // invariant: degree of a node in the more front pos
      // is always recorded earlier
      // only one distinct degree can exist before curr
      // if curr's degree matches one of previous ones,
      // it will merge in the place of curr
      // curr will be checked again if it can further grow
      // if no previously recorded node's degrees match,
      // now then curr can advance.

      Node *curr = root_;

      do {
        if (deg_arr.at(curr->degree) == nullptr) {
          // need to record
          deg_arr.at(curr->degree) = curr;
          // curr can only advance here
          if (curr->right == root_) {
            break;
          }
          curr = curr->right;
        } else {
          // need to consolidate
          Node *x = deg_arr.at(curr->degree);
          deg_arr.at(curr->degree) = nullptr;
          Node *y = curr;
          assert(x != y);
          curr = Consolidate(x, y);
        }
      } while (true);
    }
  }
  // Delete min
  DeleteNode(min_node_);
  size_--;

  if (root_ != nullptr) {
    // Update min
    Node *curr = root_;
    Node *head = root_;

    min_node_ = nullptr;
    do {
      UpdateMin(curr);
      curr = curr->right;
    } while (curr != head);
  }
  return ret_val;
}

void FibonacciHeap::DecreaseKey(int64_t value, int64_t new_key) {
  assert(root_ != nullptr);
  Node *x = node_ptr_vec_.at(value);
  assert(x);
  // if new key is already larger or equal to the x->key, skip
  if (x->key <= new_key) return;

  // decrease key
  x->key = new_key;
  // if x is in rootlist, everything is done
  if (x->parent == nullptr) {
    UpdateMin(x);
    return;
  } else if (x->key >= x->parent->key) {
    // does not violate
    return;
  }

  // detach x from parent
  // this only makes sense
  Node *curr = x;
  do {
    DetachNodeFromChildList(curr);
    AddListXToListY(curr, root_);

    curr->is_marked = false;
    UpdateMin(curr);

    num_trees_++;  // increment rootlist element count
    Node *parent = curr->parent;
    curr->parent = nullptr;
    // if parent is nullptr, then curr node in rootlist, stop
    curr = parent;
    if (curr->parent == nullptr) break;
    if (curr->is_marked == false) {
      curr->is_marked = true;
      break;
    }
  } while (true);
}

bool FibonacciHeap::IsEmpty() const {
  return size_ == 0;  // if no root exists, it is empty
}

int64_t FibonacciHeap::Size() const { return size_; }

FibonacciHeap::Node *FibonacciHeap::Consolidate(Node *x, Node *y) {
  assert(x && y);
  DetachNodeFromRootList(x);
  assert(x->left == x);
  assert(x->right == x);

  if (x->key < y->key) {
    // need swap
    SwapNodes(x, y);
    std::swap(x, y);
  }

  if (y->child == nullptr) {
    y->child = x;
  } else {
    AddListXToListY(x, y->child);
  }
  x->parent = y;
  y->degree++;
  return y;
}

void FibonacciHeap::AddListXToListY(Node *x, Node *y) {  // x -> y
  // List A should not be nullptr
  assert(x != nullptr);
  assert(y != nullptr);

  y->right->left = x->left;
  x->left->right = y->right;
  x->left = y;
  y->right = x;
}

void FibonacciHeap::DetachNodeFromRootList(Node *x) {
  assert(x);
  assert(num_trees_ >= 1);
  if (num_trees_ == 1) {
    // if node to be detached is the last, nullify root
    root_ = nullptr;
  } else if (num_trees_ >= 2) {
    // if node to be detached is root, change root
    if (x == root_) {
      root_ = root_->right;
    }
  }

  num_trees_--;
  assert(num_trees_ >= 0);
  DetachFromSiblings(x);
}

void FibonacciHeap::DetachNodeFromChildList(Node *x) {
  assert(x);
  assert(x->parent);  // parent must exist
  assert(x->parent->degree >= 1);

  if (x->parent->degree == 1) {
    // after detaching its parent has no child
    x->parent->child = nullptr;
  } else if (x->parent->degree >= 2) {
    if (x->parent->child == x) {
      x->parent->child = x->parent->child->right;
    }
  }

  x->parent->degree--;
  assert(x->parent->degree >= 0);
  DetachFromSiblings(x);
}

void FibonacciHeap::DetachFromSiblings(Node *x) {
  assert(x);

  x->right->left = x->left;
  x->left->right = x->right;
  x->right = x->left = x;  // must be pointing itself
}

void FibonacciHeap::SwapNodes(Node *x, Node *y) {
  assert(x);
  assert(y);

  if (IsSingleton(y) == true) {
    root_ = x;
  } else {
    if (y == root_) {
      root_ = x;
    }
    y->left->right = x;
    y->right->left = x;
    x->right = y->right;
    x->left = y->left;
    y->left = y->right = y;
  }

  x->parent = nullptr;
  assert(y->left == y);
  assert(y->right == y);
}

void FibonacciHeap::UpdateMin(Node *target_node) {
  assert(target_node);
  // min node should not be nullptr
  if (min_node_ == nullptr) {
    min_node_ = target_node;
  } else if (target_node->key < min_node_->key) {
    min_node_ = target_node;
  }
}

FibonacciHeap::Node *FibonacciHeap::CreateNode() const { return new Node(); }

void FibonacciHeap::DeleteNode(Node *node) {
  assert(node != nullptr);
  node_ptr_vec_.at(node->value) = nullptr;  // invalidate it
  delete node;
}

bool FibonacciHeap::IsSingleton(Node *x) {
  return x->left == x && x->right == x;
}
