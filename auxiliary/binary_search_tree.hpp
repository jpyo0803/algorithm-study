//
// Binary Search Tree as Library
//

#ifndef ALGORITHM_STUDY_BST_HPP
#define ALGORITHM_STUDY_BST_HPP

#include <iostream>

#include "basic_struct.hpp"

using ds::BinaryTreeNode;

template<typename T>
class BinarySearchTree {
public:
    virtual void TreeInsert(BinaryTreeNode<T> *new_node) {
        BinaryTreeNode<T> *current_node = root_node_;
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
            root_node_ = new_node;
        } else if (new_node->key_ < previous_node->key_) {
            previous_node->left_child_ = new_node;
        } else {
            previous_node->right_child_ = new_node;
        }
    }

    void TreeDelete(BinaryTreeNode<T> *z) {
        if (z->left_child_ == nullptr) {
            Transplant(z, z->right_child_);
        } else if (z->right_child_ == nullptr) {
            Transplant(z, z->left_child_);
        } else {
            auto y = TreeMinimum(z->right_child_);
            if (y->parent_ != z) {
                Transplant(y, y->right_child_);
                y->right_child_ = z->right_child_;
                y->right_child_->parent_ = y;
            }
            Transplant(z, y);
            y->left_child_ = z->left_child_;
            y->left_child_->parent_ = y;
        }
        if (z != nullptr) {
            delete z;
        }
    }

    BinaryTreeNode<T> *TreeSearch(T key) {
        return TreeSearchRecursive(root_node_, key);
    }

    BinaryTreeNode<T> *IterativeTreeSearch(T key) {
        BinaryTreeNode<T> *current_node = root_node_;
        while (current_node != nullptr && current_node->key_ != key) {
            if (key < current_node->key_) {
                current_node = current_node->left_child_;
            } else {
                current_node = current_node->right_child_;
            }
        }
        return current_node;
    }

    BinaryTreeNode<T> *TreeMinimum(BinaryTreeNode<T> *current_node) {
        while (current_node->left_child_ != nullptr) {
            current_node = current_node->left_child_;
        }
        return current_node;
    }

    BinaryTreeNode<T> *TreeMaximum(BinaryTreeNode<T> *current_node) {
        while (current_node->right_child_ != nullptr) {
            current_node = current_node->right_child_;
        }
        return current_node;
    }

    void InOrderTreeWalk() {
        InOrderTreeWalkRecursive(root_node_);
    }

    void PreOrderTreeWalk() {
        PreOrderTreeWalkRecursive(root_node_);
    }

    void PostInOrderTreeWalk() {
        PostOrderTreeWalkRecursive(root_node_);
    }

    BinaryTreeNode<T> *TreeSuccessor(BinaryTreeNode<T> *current_node) {
        if (current_node->right_child_ != nullptr) {
            return TreeMinimum(current_node->right_child_);
        }

        BinaryTreeNode<T>* parent_node = current_node->parent_;
        while (parent_node != nullptr && parent_node->right_child_ == current_node) {
            current_node = parent_node;
            parent_node = current_node->parent_;
        }
        return parent_node;
    }

    BinaryTreeNode<T> *TreePredecessor(BinaryTreeNode<T> *current_node) {
        if (current_node->left_child_ != nullptr) {
            return TreeMaximum(current_node->left_child_);
        }

        BinaryTreeNode<T>* parent_node = current_node->parent_;
        while (parent_node != nullptr && parent_node->left_child_ == current_node) {
            current_node = parent_node;
            parent_node = current_node->parent_;
        }
        return parent_node;
    }

    BinaryTreeNode<T>* get_root_node() {
        return root_node_;
    }

private:
    BinaryTreeNode<T> *TreeSearchRecursive(BinaryTreeNode<T> *current_node, T key) {
        if (current_node == nullptr || current_node->key_ == key) {
            return current_node;
        }

        if (key < current_node->key_) {
            return TreeSearchRecursive(current_node->left_child_, key);
        } else {
            return TreeSearchRecursive(current_node->right_child_, key);
        }
    }

    void InOrderTreeWalkRecursive(BinaryTreeNode<T> *current_node) {
        if (current_node != nullptr) {
            InOrderTreeWalkRecursive(current_node->left_child_);
            std::cout << current_node->key_ << " ";
            InOrderTreeWalkRecursive(current_node->right_child_);
        }
    }

    void PreOrderTreeWalkRecursive(BinaryTreeNode<T> *current_node) {
        if (current_node != nullptr) {
            std::cout << current_node->key_ << " ";
            PreOrderTreeWalkRecursive(current_node->left_child_);
            PreOrderTreeWalkRecursive(current_node->right_child_);
        }
    }

    void PostOrderTreeWalkRecursive(BinaryTreeNode<T> *current_node) {
        if (current_node != nullptr) {
            PostOrderTreeWalkRecursive(current_node->left_child_);
            PostOrderTreeWalkRecursive(current_node->right_child_);
            std::cout << current_node->key_ << " ";
        }
    }

    void Transplant(BinaryTreeNode<T> *u, BinaryTreeNode<T> *v) {
        if (u->parent_ == nullptr) {
            root_node_ = v;
        } else if (u->parent_->left_child_ == u) {
            u->parent_->left_child_ = v;
        } else {
            u->parent_->right_child_ = v;
        }
        if (v != nullptr) {
            v->parent_ = u->parent_;
        }
    }

 protected:
    BinaryTreeNode<T> *root_node_{nullptr};
};

#endif //ALGORITHM_STUDY_BST_HPP
