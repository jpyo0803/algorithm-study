// 경로 찾기
// https://www.acmicpc.net/problem/1513

#include <stdio.h>

int N, M, C;
int arcade_map[55][55];
int cache[55][55][55][55];

constexpr int kMod = 1'000'007;
constexpr int d[2][2] = {{-1, 0}, {0, -1}};

int Solve(int n, int m, int k, int c) {
  if (k < 0) return 0;
  if (n == 0 || m == 0) {
    if (m == 1 && k == 0) return 1;
    return 0;
  }
  if (arcade_map[n][m] > c) return 0;

  int& ret = cache[n][m][k][c];
  if (ret != -1) return ret;

  ret = 0;
  for (int i = 0; i < 2; ++i) {
    int nn = n + d[i][0];
    int nm = m + d[i][1];

    if (arcade_map[n][m] > 0) {
      ret += Solve(nn, nm, k - 1, arcade_map[n][m]);
    } else {
      ret += Solve(nn, nm, k, c);
    }
  }
  ret %= kMod;
  return ret;
}

int main() {
  scanf("%d%d%d", &N, &M, &C);
  for (int n = 1; n <= N; ++n) {
    for (int m = 1; m <= M; ++m) {
      for (int k = 0; k <= C; ++k) {
        for (int l = 0; l <= C; ++l) {
          cache[n][m][k][l] = -1;
        }
      }
    }
  }

  for (int c = 1; c <= C; ++c) {
    int x, y;
    scanf("%d%d", &x, &y);
    arcade_map[x][y] = c;
  }

  for (int i = 0; i <= C; ++i) {
    printf("%d ", Solve(N, M, i, C));
  }
  printf("\n");

  return 0;
}