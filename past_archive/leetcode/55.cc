// 55. Jump Game
// https://leetcode.com/problems/jump-game/

// This approach is not so fast, try peak-valley approach
class Solution {
 public:
  int N_;
  array<int, 10001> cache_;
  int max_found_;

  static int Max(int x, int y) { return x < y ? y : x; }

  int Solve(const vector<int>& nums, int x) {
    if (x >= N_) return 0;
    if (x == N_ - 1) return 1;

    int& ret = cache_[x];
    if (ret != -1) return ret;

    ret = 0;
    for (int d = nums[x]; d > 0; --d) {
      int nx = x + d;
      if (max_found_ < nx && Solve(nums, nx) == 1) {
        max_found_ = nx;
        ret = 1;
        break;
      }
    }

    return ret;
  }

  bool canJump(vector<int>& nums) {
    if (nums.size() == 1) return true;
    max_found_ = -1;

    N_ = nums.size();
    for (int i = 0; i < N_; ++i) cache_[i] = -1;
    return (Solve(nums, 0) == 1 ? true : false);
  }
};