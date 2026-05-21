// 198. House Robber
// https://leetcode.com/problems/house-robber/

class Solution {
 public:
  int N_;

  vector<int> cache_;

  static int Max(int x, int y) { return x < y ? y : x; }

  int Solve(const vector<int>& nums, int x) {
    int& ret = cache_[x];
    if (ret != -1) return ret;

    for (int i = 0; i < x - 1; ++i) {
      ret = Max(ret, Solve(nums, i) + nums[x]);
    }
    return ret;
  }

  int rob(vector<int>& nums) {
    N_ = nums.size();

    cache_ = vector<int>(N_, -1);

    cache_[0] = nums[0];
    if (N_ > 1) cache_[1] = nums[1];

    int ans = 0;
    for (int i = 0; i < N_; ++i) {
      ans = Max(ans, Solve(nums, i));
    }
    return ans;
  }
};