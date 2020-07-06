//
// Created by pyo on 2020-07-07.
//

#ifndef ALGORITHM_STUDY_BASIC_STRUCT_HPP
#define ALGORITHM_STUDY_BASIC_STRUCT_HPP

namespace ds { // data structure
    template<typename T>
    struct BinaryTreeNode {
        BinaryTreeNode(T key) : key_{key}, parent_{nullptr}, left_child_{nullptr}, right_child_{nullptr} {}

        T key_;
        BinaryTreeNode *parent_;
        BinaryTreeNode *left_child_;
        BinaryTreeNode *right_child_;
    };
}

#endif //ALGORITHM_STUDY_BASIC_STRUCT_HPP
