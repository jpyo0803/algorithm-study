#include "binary_search_tree.hpp"
#include "random_number_generator.hpp"
#include <iostream>

using namespace std;

int main() {
    BinarySearchTree<int> bst;

    for (int i = 0; i < 30; i++) {
        int rn = get_random_number<int>(0, 100);
        BinaryTreeNode<int>* tmp = new BinaryTreeNode<int>(rn);
        bst.TreeInsert(tmp);
    }

    cout << "Inorder Traveral : ";
    bst.InOrderTreeWalk();
    cout << endl;

    auto min_node = bst.TreeMinimum(bst.get_root_node());
    auto max_node = bst.TreeMaximum(bst.get_root_node());
    cout << "Min: " << min_node->key_ << std::endl;
    cout << "Max: " << max_node->key_ << std::endl;

    cout << "Min's Successor: " << bst.TreeSuccessor(min_node)->key_ << endl;
    cout << "Max's Predecessor: " << bst.TreePredecessor(max_node)->key_ << endl;

    auto foundNode = bst.IterativeTreeSearch(50);
    cout << "Search 50: ";
    if (foundNode != nullptr) {
        cout << "found" << endl;
    } else {
        cout << "not found" << endl;
    }

    return 0;
}