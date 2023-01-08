// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
  void Solve(vector<int>& ans, TreeNode* x) {
    if (x == nullptr) return;

    Solve(ans, x->left);
    Solve(ans, x->right);
    ans.push_back(x->val);
  }

  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    Solve(ans, root);
    return ans;
  }
};