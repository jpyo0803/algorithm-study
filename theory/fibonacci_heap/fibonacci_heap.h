#ifndef __FIBONACCI_HEAP_H__
#define __FIBONACCI_HEAP_H__

#include <assert.h>
#include <stdint.h>

#include <utility>
#include <vector>

constexpr int64_t kInvalidValue = -1e15;

class FibonacciHeap {
 private:
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
  // Declare private function and other fields to implement fibonacci heap
 public:
  FibonacciHeap(int64_t v);
  // Declare public function and other fields to implement fibonacci heap

 public:
  void Insert(int64_t new_key, int64_t new_value);

  std::pair<int64_t, int64_t> ExtractMin();

  void DecreaseKey(int64_t value, int64_t new_key);

  bool IsEmpty() const;

  int64_t Size() const;

 private:
  Node *Consolidate(Node *x, Node *y);

  void AddListXToListY(Node *x, Node *y);

  void DetachNodeFromRootList(Node *x);

  void DetachNodeFromChildList(Node *x);

  void DetachFromSiblings(Node *x);

  void SwapNodes(Node *x, Node *y);

  void UpdateMin(Node *target_node);

  Node *CreateNode() const;

  void DeleteNode(Node *node);

  bool IsSingleton(Node *x);

 private:  // make it private later
  Node *min_node_;
  Node *root_;

  int64_t num_trees_;
  int64_t size_;

  std::vector<Node *> node_ptr_vec_;
};

#endif