// 최소 스패닝 트리 (feat. 피보나치힙)
// https://www.acmicpc.net/problem/1197

#include <bits/stdc++.h>

#define DEBUG_PRINT 1

using namespace std;

constexpr int64_t kInvalidValue = -1e9;

class FibonacciHeap {
  // TODO
  // Don't forget about deallocation of a node in ExtractMin
  //  private:
 public:
  struct Node {
    int64_t key, value, degree;
    // key = weight in MST
    // value = vertex id
    bool is_marked;

    Node *parent;

    // NOTE(jpyo0803): need a pointer to only one of its children (From CLRS)
    Node *child;

    // NOTE(jpyo0803): need left and right pointers to its siblings
    // if there is only one child, child.left = child.right = child
    Node *left;
    Node *right;

    Node()
        : key(kInvalidValue),
          value(kInvalidValue),
          degree(0),
          is_marked(false),
          parent(nullptr),
          child(nullptr),
          left(this),
          right(this) {}
  };

 public:
  FibonacciHeap(int64_t v)  // v = max possible # of elements
      : min_node_(nullptr),
        root_(nullptr),
        num_trees_(0),
        size_(0),
        node_ptr_vec_(v + 10, nullptr) {}

 public:
  void Insert(int64_t new_key, int64_t new_value) {
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

  std::pair<int64_t, int64_t> ExtractMin() {  // return key, value
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
    if (num_trees_ > 0) {
      assert(root_ != nullptr);
    }
    // ready to consolidate
    // Consolidation only makes sense when num_trees >= 2
    if (num_trees_ >= 2) {
      size_t deg_arr_sz =
          static_cast<size_t>(std::log2(size_ * 3));  // VERIFY THIS
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
    if (num_trees_ > 0) {
      assert(root_ != nullptr);
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
    if (num_trees_ > 0) {
      assert(root_ != nullptr);
    }
    return ret_val;
  }

  void DecreaseKey(int64_t value, int64_t new_key) {
    assert(root_ != nullptr);
    Node *x = node_ptr_vec_.at(value);
    assert(x);
    assert(root_ != nullptr);
    // if new key is already larger or equal to the x->key, skip
    if (x->key <= new_key) return;

    // decrease key
    x->key = new_key;
    // if x is in rootlist, everything is done
    if (x->parent == nullptr) {
      assert(root_ != nullptr);
      UpdateMin(x);
      assert(root_ != nullptr);
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
    assert(root_ != nullptr);
  }

  bool IsEmpty() const {
    return size_ == 0;  // if no root exists, it is empty
  }

  int64_t Size() const { return size_; }

 private:
  Node *Consolidate(Node *x, Node *y) {
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

  void AddListXToListY(Node *x, Node *y) {  // x -> y
    // List A should not be nullptr
    assert(x != nullptr);
    assert(y != nullptr);

    y->right->left = x->left;
    x->left->right = y->right;
    x->left = y;
    y->right = x;
  }

  void DetachNodeFromRootList(Node *x) {
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

  void DetachNodeFromChildList(Node *x) {
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

  void DetachFromSiblings(Node *x) {
    assert(x);

    x->right->left = x->left;
    x->left->right = x->right;
    x->right = x->left = x;  // must be pointing itself
  }

  void SwapNodes(Node *x, Node *y) {
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

  void UpdateMin(Node *target_node) {
    assert(target_node);
    // min node should not be nullptr
    if (min_node_ == nullptr) {
      min_node_ = target_node;
    } else if (target_node->key < min_node_->key) {
      min_node_ = target_node;
    }
  }

  Node *CreateNode() const { return new Node(); }

  void DeleteNode(Node *node) {
    assert(node != nullptr);
    node_ptr_vec_.at(node->value) = nullptr;  // invalidate it
    delete node;
  }

  bool IsSingleton(Node *x) { return x->left == x && x->right == x; }

  // private: // make it private later
 public:
  Node *min_node_;
  Node *root_;

  int64_t num_trees_;
  int64_t size_;

  std::vector<Node *> node_ptr_vec_;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  FibonacciHeap *fh = nullptr;

  fh = new FibonacciHeap(10010);
  assert(fh != nullptr);
  assert(fh->IsEmpty() == true);

  // MST
  int V, E;
  cin >> V >> E;

  constexpr int64_t kInf = 1e16;

  vector<bool> S(V + 10, false);
  vector<int64_t> dist(V + 10);
  for (int i = 1; i <= V; ++i) {
    if (i == 1) {
      dist.at(i) = 0;
      fh->Insert(0, i);
    } else {
      dist.at(i) = kInf;
      fh->Insert(kInf, i);
    }
  }

  vector<vector<pair<int, int64_t>>> adj(V + 10);

  long long ans = 0;
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj.at(u).emplace_back(v, w);
    adj.at(v).emplace_back(u, w);
  }

  while (fh->IsEmpty() == false) {
    assert(fh->root_ != nullptr);
    auto ret = fh->ExtractMin();
    int64_t u = ret.second;  // value
    if (fh->Size()) {
      assert(fh->root_ != nullptr);
    }

    for (auto e : adj.at(u)) {
      int64_t v = e.first;
      int64_t w = e.second;
      if (S.at(v) == true) continue;  // already in S, skip

      if (w < dist.at(v)) {
        dist.at(v) = w;
        fh->DecreaseKey(v, w);
      }
    }

    S.at(u) = true;
    ans += ret.first;
  }

  cout << ans << "\n";

  if (fh != nullptr) {
    delete fh;
  }

  return 0;
}