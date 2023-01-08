// 343. Integer Break
// https://leetcode.com/problems/integer-break/

class Solution {
 public:
  static int Max(int x, int y) { return x < y ? y : x; }

  vector<int> cache_;

  int Solve(int n) {
    if (n < 0) return 0;
    if (n == 1) return 1;

    int& ret = cache_[n];
    if (ret != -1) return ret;

    ret = n;
    for (int i = 1; i <= n / 2; ++i) {
      ret = Max(ret, Solve(n - i) * Solve(i));
    }
    return ret;
  }

  int integerBreak(int n) {
    cache_ = vector<int>(n + 1, -1);
    int ans = 0;
    for (int i = 1; i <= n / 2; ++i) {
      ans = Max(ans, Solve(n - i) * Solve(i));
    }
    return ans;
  }
};