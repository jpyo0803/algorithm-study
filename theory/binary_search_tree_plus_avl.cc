#include <iostream>

#include "avl_binary_search_tree.hpp"
#include "binary_search_tree.hpp"

using namespace std;

int main() {
  BinarySearchTree<int> bst;
  AVLBinarySearchTree<int> avl_bst;

  for (int i = 0; i < 10000; i++) {
    BinaryTreeNode<int> *tmp1 = new BinaryTreeNode<int>(i + 1);
    BinaryTreeNode<int> *tmp2 = new BinaryTreeNode<int>(i + 1);
    bst.TreeInsert(tmp1);
    avl_bst.TreeInsert(tmp2);
  }

  //  cout << "Inorder Traveral of BST: ";
  //  bst.InOrderTreeWalk();
  //  cout << endl;
  //
  //  cout << "Inorder Traveral of AVL BST : ";
  //  avl_bst.InOrderTreeWalk();
  //  cout << endl;

  cout << "BST search 1\n";
  bst.IterativeTreeSearch(10000);

  cout << "AVL BST search 1\n";
  avl_bst.IterativeTreeSearch(10000);

  //    auto min_node = bst.TreeMinimum(bst.get_root_node());
  //    auto max_node = bst.TreeMaximum(bst.get_root_node());
  //    cout << "Min: " << min_node->key_ << std::endl;
  //    cout << "Max: " << max_node->key_ << std::endl;
  //
  //    cout << "Min's Successor: " << bst.TreeSuccessor(min_node)->key_ <<
  //    endl; cout << "Max's Predecessor: " <<
  //    bst.TreePredecessor(max_node)->key_ << endl;
  //
  //    auto foundNode = bst.IterativeTreeSearch(50);
  //    cout << "Search 50: ";
  //    if (foundNode != nullptr) {
  //        cout << "found" << endl;
  //    } else {
  //        cout << "not found" << endl;
  //    }
  //
  //    auto foundNode2 = bst.TreeSearch(1);
  //    if (foundNode2 != nullptr) {
  //        bst.TreeDelete(foundNode2);
  //    }
  //
  //    auto foundNode3 = bst.TreeSearch(5);
  //    if (foundNode3 != nullptr) {
  //        bst.TreeDelete(foundNode3);
  //    }
  //
  //    cout << "Inorder Traveral : ";
  //    bst.InOrderTreeWalk();
  //    cout << endl;

  return 0;
}