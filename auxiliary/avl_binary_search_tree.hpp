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
    } else {
      if (new_node->key_ < previous_node->key_) {
        previous_node->left_child_ = new_node;
      } else {
        previous_node->right_child_ = new_node;
      }
    }

    current_node = new_node;

    while (current_node != nullptr) {
      int bal = balance(current_node);
      auto parent = current_node->parent_;
      if (bal > 1) {
        if (balance(current_node->left_child_) < 0) {
          current_node->left_child_ = RotateLeft(current_node->left_child_);
        }
        current_node = RotateRight(current_node);
        if (parent != nullptr) {
          if (parent->key_ > current_node->key_) {
            parent->left_child_ = current_node;
          } else {
            parent->right_child_ = current_node;
          }
        }
      } else if (bal < -1) {
        if (balance(current_node->right_child_) > 0) {
          current_node->right_child_ = RotateRight(current_node->right_child_);
        }
        current_node = RotateLeft(current_node);
        if (parent != nullptr) {
          if (parent->key_ > current_node->key_) {
            parent->left_child_ = current_node;
          } else {
            parent->right_child_ = current_node;
          }
        }
      }
      if (current_node->parent_ == nullptr) {
        this->root_node_ = current_node;
      }
      current_node->height_ = max(height(current_node->left_child_), height(current_node->right_child_)) + 1;
      current_node = current_node->parent_;
    }
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
    auto y = x->right_child_;

    x->right_child_ = y->left_child_;
    y->parent_ = x->parent_;
    x->parent_ = y;
    y->left_child_ = x;
    x->height_ = max(height(x->left_child_), height(x->right_child_)) + 1;
    y->height_ = max(height(y->left_child_), height(y->right_child_)) + 1;
    return y;
  }

  BinaryTreeNode<T> *RotateRight(BinaryTreeNode<T> *y) {
    auto x = y->left_child_;

    y->left_child_ = x->right_child_;
    x->parent_ = y->parent_;
    y->parent_ = x;
    x->right_child_ = y;
    y->height_ = max(height(y->left_child_), height(y->right_child_)) + 1;
    x->height_ = max(height(x->left_child_), height(x->right_child_)) + 1;
    return x;
  }
};

#endif //ALGORITHM_STUDY_AVL_BINARY_SEARCH_TREE_HPP
