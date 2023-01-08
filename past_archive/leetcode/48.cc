// 48. Rotate Image
// https://leetcode.com/problems/rotate-image/

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    const int N = matrix.size();
    vector<vector<int>> ans(N, vector<int>(N));

    for (int r = 0; r < N; ++r) {
      for (int c = 0; c < N; ++c) {
        ans[c][N - 1 - r] = matrix[r][c];
      }
    }
    matrix = move(ans);
  }
};