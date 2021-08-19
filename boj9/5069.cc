// 미로에 갇힌 상근
// https://www.acmicpc.net/problem/5069

#include <stdio.h>

int T, N;

int hive[40][40];
int cache[40][40][15];
bool visited[40][40][15];

int Solve(int r, int c, int n, bool odd) {
  if (n == 0) {
    if (r == 20 && c == 20) return 1;
    return 0;
  }

  if (visited[r][c][n]) return 0;

  int& ret = cache[r][c][n];
  if (ret != -1) return ret;

  visited[r][c][n] = true;

  ret = 0;
  ret += Solve(r - 1, c + odd, n - 1, !odd);
  ret += Solve(r - 1, c - 1 + odd, n - 1, !odd);

  ret += Solve(r, c - 1, n - 1, odd);
  ret += Solve(r, c + 1, n - 1, odd);

  ret += Solve(r + 1, c - 1 + odd, n - 1, !odd);
  ret += Solve(r + 1, c + odd, n - 1, !odd);

  visited[r][c][n] = false;
  return ret;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < 40; ++i) {
      for (int j = 0; j < 40; ++j) {
        for (int k = 0; k < 15; ++k) {
          cache[i][j][k] = -1;
        }
      }
    }
    scanf("%d", &N);
    printf("%d\n", Solve(20, 20, N, true));
  }
  return 0;
}