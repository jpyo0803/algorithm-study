// 59. Spiral Matrix II
// https://leetcode.com/problems/spiral-matrix-ii/

// First Try
class Solution {
 public:
  static constexpr int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  int N_;

  void Solve(vector<vector<int>>& mat, int r, int c, int x, int dir) {
    mat[r][c] = x;
    int nr = r + d[dir][0];
    int nc = c + d[dir][1];
    if (nr < 0 || nr == N_ || nc < 0 || nc == N_ || mat[nr][nc] != -1) {
      ++dir;
      dir %= 4;
      nr = r + d[dir][0];
      nc = c + d[dir][1];
    }
    if ((nr >= 0 && nr < N_ && nc >= 0 && nc < N_) && mat[nr][nc] == -1) {
      Solve(mat, nr, nc, x + 1, dir);
    }
  }

  vector<vector<int>> generateMatrix(int n) {
    N_ = n;
    vector<vector<int>> mat(n, vector<int>(n, -1));
    Solve(mat, 0, 0, 1, 0);
    return mat;
  }
};

// Layer Filling
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> mat(n, vector<int>(n));

    int x = 1;
    for (int layer = 0; layer < (n + 1) / 2; ++layer) {
      for (int c = layer; c < n - layer; ++c) {
        mat[layer][c] = x++;
      }
      for (int r = layer + 1; r < n - layer; ++r) {
        mat[r][n - layer - 1] = x++;
      }
      for (int c = n - layer - 2; c >= layer; --c) {
        mat[n - layer - 1][c] = x++;
      }
      for (int r = n - layer - 2; r > layer; --r) {
        mat[r][layer] = x++;
      }
    }
    return mat;
  }
};