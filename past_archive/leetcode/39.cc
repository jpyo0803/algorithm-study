// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/

class Solution {
 public:
  void Solve(vector<vector<int>>& ans, vector<int>&& local_ans,
             const vector<int>& candidates, int sum, const int target,
             int last) {
    if (sum >= target) {
      if (sum == target) ans.push_back(local_ans);
      return;
    }

    for (int i = last; i < candidates.size(); ++i) {
      local_ans.push_back(candidates[i]);
      Solve(ans, move(local_ans), candidates, sum + candidates[i], target, i);
      local_ans.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    Solve(ans, move(vector<int>()), candidates, 0, target, 0);
    return ans;
  }
};