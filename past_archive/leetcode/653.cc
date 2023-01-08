// 653. Two Sum IV - Input is a BST
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
  unordered_set<int> mm_;

  bool ans_;
  void Solve(TreeNode* root, int target) {
    if (ans_) return;
    if (root == nullptr) return;

    int d = target - root->val;
    if (mm_.find(d) != mm_.end()) {
      ans_ = true;
      return;
    }
    mm_.insert(root->val);
    Solve(root->left, target);
    Solve(root->right, target);
  }

  bool findTarget(TreeNode* root, int k) {
    ans_ = false;
    Solve(root, k);
    return ans_;
  }
};