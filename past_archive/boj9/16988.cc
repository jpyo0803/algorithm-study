// Baaaaaaaaaduk2 (Easy)
// https://www.acmicpc.net/problem/16988

#include <stdio.h>

int N, M;

int board[22][22];
bool visited[22][22];

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool InRange(int i, int j) { return i >= 0 && i < N && j >= 0 && j < M; }

int Max(int x, int y) { return x < y ? y : x; }

void Dfs(int i, int j, int& zc, int& tc) {
  visited[i][j] = true;
  ++tc;
  for (int k = 0; k < 4; ++k) {
    int ni = i + d[k][0];
    int nj = j + d[k][1];
    if (!InRange(ni, nj)) continue;
    if (board[ni][nj] == 0) ++zc;
    if (board[ni][nj] != 2) continue;
    if (visited[ni][nj]) continue;
    Dfs(ni, nj, zc, tc);
  }
}

int GetScore() {
  int two_count = 0;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      visited[i][j] = false;
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (board[i][j] != 2) continue;
      if (visited[i][j]) continue;
      int zc = 0, tc = 0;
      Dfs(i, j, zc, tc);
      if (zc == 0) {
        two_count += tc;
      }
    }
  }

  return two_count;
}

int Solve() {
  int ans = 0;
  for (int i = 0; i < N * M; ++i) {
    int ir = i / M;
    int ic = i % M;
    if (board[ir][ic] != 0) continue;
    for (int j = i + 1; j < N * M; ++j) {
      int jr = j / M;
      int jc = j % M;
      if (board[jr][jc] != 0) continue;

      board[ir][ic] = board[jr][jc] = 1;
      ans = Max(ans, GetScore());
      board[ir][ic] = board[jr][jc] = 0;
    }
  }
  return ans;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int n = 0; n < N; ++n) {
    for (int m = 0; m < M; ++m) {
      scanf("%d", &board[n][m]);
    }
  }

  printf("%d\n", Solve());
  return 0;
}