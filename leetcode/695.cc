// 695. Max Area of Island
// https://leetcode.com/problems/max-area-of-island/

class Solution {
 public:
  static int Max(int x, int y) { return x < y ? y : x; }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int ans = 0;

    const int M = grid.size();
    const int N = grid[0].size();

    vector<vector<bool>> check(M, vector<bool>(N, false));

    int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (check[i][j] || grid[i][j] != 1) continue;

        int count = 0;

        queue<pair<int, int>> que;
        que.emplace(i, j);
        check[i][j] = true;

        while (!que.empty()) {
          int r = que.front().first;
          int c = que.front().second;
          que.pop();
          ++count;

          for (int k = 0; k < 4; ++k) {
            int nr = r + d[k][0];
            int nc = c + d[k][1];
            if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
            if (grid[nr][nc] != 1) continue;
            if (check[nr][nc]) continue;

            check[nr][nc] = true;
            que.emplace(nr, nc);
          }
        }
        ans = Max(ans, count);
      }
    }
    return ans;
  }
};