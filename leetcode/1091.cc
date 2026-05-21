// 1091. Shortest Path in Binary Matrix
// https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    const int M = grid.size();
    const int N = grid[0].size();

    if (grid[0][0] == 1) return -1;

    vector<vector<bool>> check(M, vector<bool>(N, false));
    queue<pair<pair<int, int>, int>> que;

    check[0][0] = true;
    que.emplace(make_pair(0, 0), 1);

    constexpr int d[8][2] = {{0, 1}, {0, -1},  {1, 0},  {-1, 0},
                             {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    auto check_range = [M, N](int r, int c) -> int {
      return r >= 0 && r < M && c >= 0 && c < N;
    };

    int ans = -1;
    while (!que.empty()) {
      int r = que.front().first.first;
      int c = que.front().first.second;
      int dist = que.front().second;

      que.pop();

      if (r == M - 1 && c == N - 1) {
        ans = dist;
        break;
      }

      for (int k = 0; k < 8; ++k) {
        int nr = r + d[k][0];
        int nc = c + d[k][1];

        if (!check_range(nr, nc)) continue;
        if (grid[nr][nc] != 0) continue;
        if (check[nr][nc]) continue;
        check[nr][nc] = true;
        que.emplace(make_pair(nr, nc), dist + 1);
      }
    }
    return ans;
  }
};