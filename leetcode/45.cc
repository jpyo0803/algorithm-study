// 45. Jump Game II
// https://leetcode.com/problems/jump-game-ii/

// Memoization
class Solution {
 public:
  vector<int> cache_;
  vector<int> nums_;

  static int Min(int x, int y) { return x < y ? x : y; }

  bool CheckRange(int x) { return x >= 0 && x < nums_.size(); }

  int Solve(int x) {
    if (x == nums_.size() - 1) return 0;

    int& ret = cache_[x];
    if (ret != -1) return ret;
    ret = 987654321;

    int mj = nums_[x];
    for (int i = 1; i <= mj; ++i) {
      if (!CheckRange(x + i)) break;
      ret = Min(ret, Solve(x + i) + 1);
    }
    return ret;
  }

  int jump(vector<int>& nums) {
    cache_ = vector<int>(nums.size(), -1);
    nums_ = std::move(nums);

    return Solve(0);
  }
};

// Tabulate
class Solution {
 public:
  static int Min(int x, int y) { return x < y ? x : y; }

  int jump(vector<int>& nums) {
    vector<int> cache = vector<int>(nums.size(), 987654321);

    cache[0] = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      int mj = nums[i];
      for (int j = 1; j <= mj; ++j) {
        if (!(i + j >= 0 && i + j < nums.size())) break;
        cache[i + j] = Min(cache[i + j], cache[i] + 1);
      }
    }

    return cache.back();
  }
};