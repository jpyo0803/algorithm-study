//
// Gerrymandering 2
// Link: https://www.acmicpc.net/problem/17779
//

#include <cstdio>
#include <cstring>

constexpr int INF = 987654321;

int Max(int x, int y) { return x > y ? x : y; }
int Min(int x, int y) { return x < y ? x : y; }

int N;
int A[21][21];
int pc[5];
int tc = 0;

int Solve() {
  int gmin = INF;

  for (int d1 = 1; d1 <= N; d1++) {
    for (int d2 = 1; d2 <= N; d2++) {
      for (int x = 1; x <= N - d1 - d2; x++) {
        for (int y = 1 + d1; y <= N - d2; y++) {
          memset(pc, 0, sizeof(pc));
          for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
              if (r < x + d1 && c <= y && r < x + y - c)
                pc[0] += A[r][c];
              else if (r <= x + d2 && c > y && c > y - x + r)
                pc[1] += A[r][c];
              else if (r >= x + d1 && c < y - d1 + d2 &&
                       c < y + r - x - (2 * d1))
                pc[2] += A[r][c];
              else if (r > x + d2 && y - d1 + d2 <= c &&
                       r > x - c + y + (2 * d2))
                pc[3] += A[r][c];
            }
          }
          pc[4] = tc - (pc[0] + pc[1] + pc[2] + pc[3]);
          bool is_zero = false;
          for (int i = 0; i < 5 && !is_zero; i++) {
            if (pc[i] == 0) is_zero = true;
          }
          if (!is_zero) {
            int lmax = -INF;
            int lmin = INF;
            for (int i = 0; i < 5; i++) {
              lmax = Max(lmax, pc[i]);
              lmin = Min(lmin, pc[i]);
            }
            gmin = Min(gmin, lmax - lmin);
          }
        }
      }
    }
  }
  return gmin;
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      scanf("%d", &A[i][j]);
      tc += A[i][j];
    }
  }
  printf("%d\n", Solve());

  return 0;
}