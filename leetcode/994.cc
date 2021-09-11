// 994. Rotting Oranges
// https://leetcode.com/problems/rotting-oranges/

class Solution {
 public:
  static constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  int orangesRotting(vector<vector<int>>& grid) {
    const int M = grid.size();
    const int N = grid[0].size();

    vector<pair<int, int>> frontier, next;
    vector<vector<bool>> check(M, vector<bool>(N, false));

    int fresh_count = 0;

    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (grid[i][j] == 1) ++fresh_count;
        if (grid[i][j] != 2) continue;
        frontier.emplace_back(i, j);
        check[i][j] = true;
      }
    }

    if (fresh_count == 0) return 0;

    int level = -1;
    while (!frontier.empty()) {
      next.clear();
      for (const auto& p : frontier) {
        for (int i = 0; i < 4; ++i) {
          int nr = p.first + d[i][0];
          int nc = p.second + d[i][1];

          if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
          if (check[nr][nc]) continue;
          if (grid[nr][nc] != 1) continue;
          --fresh_count;
          check[nr][nc] = true;
          next.emplace_back(nr, nc);
        }
      }
      ++level;
      frontier.swap(next);
    }

    return (fresh_count > 0 ? -1 : level);
  }
};