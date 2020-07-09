//
// Created by pyo on 2020-07-09.
//

#ifndef ALGORITHM_STUDY_AVL_BINARY_SEARCH_TREE_HPP
#define ALGORITHM_STUDY_AVL_BINARY_SEARCH_TREE_HPP

#include "binary_search_tree.hpp"
#include "basic_struct.hpp"

using ds::BinaryTreeNode;

template<typename T>
class AVLBinarySearchTree : public BinarySearchTree<T> {
 public:
  virtual void TreeInsert(BinaryTreeNode<T> *new_node) override {
    BinaryTreeNode<T> *current_node = this->root_node_;
    BinaryTreeNode<T> *previous_node = nullptr;

    while (current_node != nullptr) {
      previous_node = current_node;
      if (new_node->key_ < current_node->key_) {
        current_node = current_node->left_child_;
      } else {
        current_node = current_node->right_child_;
      }
    }

    new_node->parent_ = previous_node;
    if (previous_node == nullptr) {
      this->root_node_ = new_node;
    } else if (new_node->key_ < previous_node->key_) {
      previous_node->left_child_ = new_node;
    } else {
      previous_node->right_child_ = new_node;
    }

    current_node = new_node;
    previous_node = nullptr;

    while (current_node != nullptr) {
      previous_node = current_node;
      current_node->height_ = max(height(current_node->left_child_), height(current_node->right_child_)) + 1;
      int bal = balance(current_node);

      if (bal > 1) {
        if (balance(current_node->left_child_) <= -1) {
          current_node->left_child_ = RotateLeft(current_node->left_child_);
        }
        current_node = RotateRight(current_node);
      } else if (bal < -1) {
        if (balance(current_node->right_child_) >= 1) {
          current_node->right_child_ = RotateRight(current_node->right_child_);
        }
        current_node = RotateLeft(current_node);
      }
      current_node = current_node->parent_;
    }
    this->root_node_ = previous_node;
  }

 private:
  int height(BinaryTreeNode<T> *node) const {
    if (node == nullptr) return 0;
    return node->height_;
  }

  int balance(BinaryTreeNode<T> *node) const {
    if (node == nullptr) return 0;
    return height(node->left_child_) - height(node->right_child_);
  }

  int max(int x, int y) { return (x > y) ? x : y; }

  BinaryTreeNode<T> *RotateLeft(BinaryTreeNode<T> *x) {
    BinaryTreeNode<T> *y = x->right_child_;

    x->right_child_ = y->left_child_;
    y->left_child_ = x;
    y->parent_ = x->parent_;
    x->parent_ = y;
    x->height_ = max(height(x->left_child_), height(x->right_child_)) + 1;
    y->height_ = max(height(y->left_child_), height(y->right_child_)) + 1;
    return y;
  }

  BinaryTreeNode<T> *RotateRight(BinaryTreeNode<T> *y) {
    BinaryTreeNode<T> *x = y->left_child_;

    y->left_child_ = x->right_child_;
    x->right_child_ = y;
    x->parent_ = y->parent_;
    y->parent_ = x;
    x->height_ = max(height(x->left_child_), height(x->right_child_)) + 1;
    y->height_ = max(height(y->left_child_), height(y->right_child_)) + 1;
    return x;
  }
};

#endif //ALGORITHM_STUDY_AVL_BINARY_SEARCH_TREE_HPP
