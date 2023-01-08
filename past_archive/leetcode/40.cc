// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/

class Solution {
 public:
  void Solve(vector<vector<int>>& ans, vector<int>&& local_ans,
             vector<int>& recand, int sum, const int target, int last) {
    if (sum >= target) {
      if (sum == target) ans.push_back(local_ans);
      return;
    }

    for (int i = last; i < 51; ++i) {
      if (recand[i] == 0) continue;
      --recand[i];
      local_ans.push_back(i);
      Solve(ans, move(local_ans), recand, sum + i, target, i);
      local_ans.pop_back();
      ++recand[i];
    }
  }

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> recand(51, 0);
    for (auto candidate : candidates) {
      ++recand[candidate];
    }
    Solve(ans, move(vector<int>()), recand, 0, target, 0);
    return ans;
  }
};