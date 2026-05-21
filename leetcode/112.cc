// 112. Path Sum
// https://leetcode.com/problems/path-sum/

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
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    int ns = targetSum - root->val;
    if (!root->left && !root->right && ns == 0) return true;

    bool ret = false;
    if (root->left) ret |= hasPathSum(root->left, ns);
    if (root->right) ret |= hasPathSum(root->right, ns);
    return ret;
  }
};