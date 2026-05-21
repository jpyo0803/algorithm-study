// 47. Permutations II
// https://leetcode.com/problems/permutations-ii/

class Solution {
 public:
  unordered_map<int, int> num_count_;

  void Solve(vector<vector<int>>& ans, vector<int>&& cand,
             const vector<int>& nums) {
    if (cand.size() == nums.size()) {
      ans.push_back(cand);
      return;
    }

    for (auto& p : num_count_) {
      if (p.second == 0) continue;
      --p.second;
      cand.push_back(p.first);
      Solve(ans, move(cand), nums);
      cand.pop_back();
      ++p.second;
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    for (auto num : nums) {
      ++num_count_[num];
    }
    vector<vector<int>> ans;
    Solve(ans, move(vector<int>()), nums);
    return ans;
  }
};