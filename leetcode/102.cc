// 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;

    vector<int> local_ans;
    vector<TreeNode*> frontier, next;

    frontier.push_back(root);
    local_ans.push_back(root->val);
    while (!frontier.empty()) {
      ans.push_back(local_ans);
      local_ans.clear();
      for (auto x : frontier) {
        if (x->left != nullptr) {
          next.push_back(x->left);
          local_ans.push_back(x->left->val);
        }
        if (x->right != nullptr) {
          next.push_back(x->right);
          local_ans.push_back(x->right->val);
        }
      }
      frontier.swap(next);
      next.clear();
    }
    return ans;
  }
};