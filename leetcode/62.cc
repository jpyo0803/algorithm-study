// 62. Unique Paths
// https://leetcode.com/problems/unique-paths/

class Solution {
 public:
  vector<vector<int>> cache_;

  int Solve(int r, int c) {
    if (r < 0 || c < 0) return 0;
    if (r == 0 && c == 0) return 1;

    int& ret = cache_[r][c];
    if (ret != -1) return ret;

    return cache_[r][c] = Solve(r - 1, c) + Solve(r, c - 1);
  }

  int uniquePaths(int m, int n) {
    cache_ = vector<vector<int>>(m, vector<int>(n, -1));
    return Solve(m - 1, n - 1);
  }
};