// Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/

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
  bool Solve(TreeNode* u, long long int ll, long long int ul) {
    if (u == nullptr) return true;

    if (u->val <= ll || u->val >= ul) return false;
    return Solve(u->left, ll, u->val) && Solve(u->right, u->val, ul);
  }

  bool isValidBST(TreeNode* root) {
    return Solve(root, -9876543210, 9876543210);
  }
};