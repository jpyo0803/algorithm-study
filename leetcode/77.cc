// 77. Combination
// https://leetcode.com/problems/combinations/

class Solution {
 public:
  void Solve(vector<vector<int>>& ans, vector<int>&& cand, int n, int k,
             int nth) {
    if (nth == k + 1) {
      ans.push_back(cand);
      return;
    }

    int i = 1;
    if (nth > 1) i = cand.back() + 1;
    for (; i <= n; ++i) {
      cand.push_back(i);
      Solve(ans, std::move(cand), n, k, nth + 1);
      cand.pop_back();
    }
  }

  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    Solve(ans, std::move(vector<int>()), n, k, 1);
    return ans;
  }
};