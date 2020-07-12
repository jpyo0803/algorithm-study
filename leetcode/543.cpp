//
// Diameter of Binary Tree
// Problem: https://leetcode.com/problems/diameter-of-binary-tree/
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
 public:
  int max_diameter = 0;

  int diameterOfBinaryTree(TreeNode *root) {
    dfs(root);
    return max_diameter;
  }

  int dfs(TreeNode *current_node) {
    if (current_node == nullptr) {
      return 0;
    }

    int radius_left = dfs(current_node->left);
    int radius_right = dfs(current_node->right);

    max_diameter = max(max_diameter, radius_left + radius_right);

    return max(radius_left, radius_right) + 1;
  }
};
