//
// Maximum Depth of Binary Tree
// Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree/
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// First Try
int Max(int x, int y) { return x < y ? y : x; }

class Solution {
 public:
  int maxDepth(TreeNode* root) {
    int h = 0;
    if (root == nullptr) return h;
    h = Max(maxDepth(root->right) + 1, maxDepth(root->left) + 1);
    return h;
  }
};

// Second Try
class Solution {
 public:
  static int Max(int x, int y) { return x < y ? y : x; }

  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    return Max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};