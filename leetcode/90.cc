// 90. Subsets II
// https://leetcode.com/problems/subsets-ii/

class Solution {
 public:
  void Solve(const vector<pair<int, int>>& nc, vector<vector<int>>& ans,
             vector<int>&& cand, int nth) {
    if (nc.size() == nth) {
      ans.push_back(cand);
      return;
    }

    for (int i = 0; i <= nc[nth].second; ++i) {
      int j = i;
      while (j > 0) {
        cand.push_back(nc[nth].first);
        --j;
      }
      Solve(nc, ans, move(cand), nth + 1);
      j = i;
      while (j > 0) {
        cand.pop_back();
        --j;
      }
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<pair<int, int>> nc;

    sort(nums.begin(), nums.end());
    int tn = -100;
    int count = 0;

    int i = 0;
    while (i < nums.size()) {
      if (tn == -100)
        tn = nums[i];
      else {
        if (nums[i] != tn) {
          nc.emplace_back(tn, count);
          tn = nums[i];
          count = 0;
        }
      }
      ++count;
      if (i == nums.size() - 1) {
        nc.emplace_back(tn, count);
      }
      ++i;
    }

    vector<vector<int>> ans;
    Solve(nc, ans, move(vector<int>()), 0);
    return ans;
  }
};