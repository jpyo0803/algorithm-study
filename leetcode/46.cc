// 46. Permutations
// https://leetcode.com/problems/permutations/

class Solution {
 public:
  vector<bool> used_;

  void Solve(vector<vector<int>>& ans, vector<int>& nums, vector<int>&& cand) {
    if (cand.size() == nums.size()) {
      ans.push_back(cand);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (!used_[i]) {
        used_[i] = true;
        cand.push_back(nums[i]);
        Solve(ans, nums, std::move(cand));
        cand.pop_back();
        used_[i] = false;
      }
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    used_ = vector<bool>(nums.size());
    vector<vector<int>> ans;
    Solve(ans, nums, std::move(vector<int>()));
    return ans;
  }
};