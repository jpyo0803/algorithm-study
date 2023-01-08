//
// Created by pyo on 2020-07-07.
//

#ifndef ALGORITHM_STUDY_BASIC_STRUCT_HPP
#define ALGORITHM_STUDY_BASIC_STRUCT_HPP

namespace ds { // data structure
    template<typename T>
    struct BinaryTreeNode {
        BinaryTreeNode(T key) : key_{key} {}

        T key_;
        BinaryTreeNode *parent_{nullptr};
        BinaryTreeNode *left_child_{nullptr};
        BinaryTreeNode *right_child_{nullptr};

        int height_{0};
    };
}

#endif //ALGORITHM_STUDY_BASIC_STRUCT_HPP
