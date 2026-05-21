// 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/

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
class Solution {
 public:
  bool Solve(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) return true;
    if (!(right && left)) return false;
    if (right->val != left->val) return false;
    return Solve(left->right, right->left) && Solve(left->left, right->right);
  }

  bool isSymmetric(TreeNode* root) { return Solve(root->left, root->right); }
};