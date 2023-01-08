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
  TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* pn = nullptr;
    TreeNode* tn = FindMatch(root, key, &pn);
    if (tn == nullptr) return root;
    TreeNode* mst = MergeSubtrees(tn);
    if (pn != nullptr) {
      if (pn->left == tn)
        pn->left = mst;
      else
        pn->right = mst;
    } else {
      root = mst;
    }
    return root;
  }

 private:
  static TreeNode* MergeSubtrees(TreeNode* cn) {
    TreeNode* lc = cn->left;
    TreeNode* rc = cn->right;
    TreeNode* pn = cn;

    if (rc != nullptr) {
      TreeNode* sor = FindSmallest(rc, &pn);
      sor->left = lc;
      if (pn != cn) pn->left = sor->right;
      return sor;
    } else if (lc != nullptr) {
      TreeNode* lol = FindLargest(lc, &pn);
      lol->right = rc;
      if (pn != cn) pn->right = lol->left;
      return lol;
    }
    return nullptr;
  }

  static TreeNode* FindSmallest(TreeNode* cn, TreeNode** pn) {
    if (cn->left == nullptr)
      return cn;
    else {
      *pn = cn;
      return FindSmallest(cn->left, pn);
    }
  }

  static TreeNode* FindLargest(TreeNode* cn, TreeNode** pn) {
    if (cn->right == nullptr)
      return cn;
    else {
      *pn = cn;
      return FindLargest(cn->right, pn);
    }
  }

  static TreeNode* FindMatch(TreeNode* cn, int key, TreeNode** pn) {
    if (cn == nullptr) return nullptr;
    if (cn->val < key) {
      *pn = cn;
      return FindMatch(cn->right, key, pn);
    } else if (cn->val > key) {
      *pn = cn;
      return FindMatch(cn->left, key, pn);
    } else {
      return cn;
    }
  }
};