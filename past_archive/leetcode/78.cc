// 78. Subsets
// https://leetcode.com/problems/subsets/

class Solution {
 public:
  void Solve(const vector<int>& nums, vector<vector<int>>& ans,
             vector<int>&& cand, int nth) {
    if (nth == nums.size()) {
      ans.push_back(cand);
      return;
    }

    Solve(nums, ans, move(cand), nth + 1);
    cand.push_back(nums[nth]);
    Solve(nums, ans, move(cand), nth + 1);
    cand.pop_back();
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    Solve(nums, ans, move(vector<int>()), 0);
    return ans;
  }
};