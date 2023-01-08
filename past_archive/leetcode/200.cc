// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/

class Solution {
 public:
  static constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  vector<vector<bool>> check_;

  int M_, N_;

  bool CheckRange(int r, int c) { return r >= 0 && r < M_ && c >= 0 && c < N_; }

  void Solve(const vector<vector<char>>& grid, int r, int c) {
    check_[r][c] = true;

    for (int i = 0; i < 4; ++i) {
      int nr = r + d[i][0];
      int nc = c + d[i][1];
      if (!CheckRange(nr, nc) || check_[nr][nc] || grid[nr][nc] != '1')
        continue;
      Solve(grid, nr, nc);
    }
  }

  int numIslands(vector<vector<char>>& grid) {
    M_ = grid.size();
    N_ = grid[0].size();

    check_ = vector<vector<bool>>(M_, vector<bool>(N_, false));

    int ans = 0;
    for (int i = 0; i < M_; ++i) {
      for (int j = 0; j < N_; ++j) {
        if (grid[i][j] != '1') continue;
        if (check_[i][j]) continue;
        Solve(grid, i, j);
        ++ans;
      }
    }
    return ans;
  }
};