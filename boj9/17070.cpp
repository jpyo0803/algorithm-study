// 파이프 옮기기 1
// https://www.acmicpc.net/problem/17070

#include <stdio.h>

int N;
bool map[16][16];
int cache[16][16][3];

bool InRange(int i, int j) { return i >= 0 && i < N && j >= 0 && j < N; }

int Solve() {
  cache[0][1][0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (map[i][j]) continue;
      if (InRange(i, j - 1)) {
        cache[i][j][0] += cache[i][j - 1][0];  // 1
        cache[i][j][0] += cache[i][j - 1][1];  // 5
      }
      if (InRange(i - 1, j - 1) && !map[i - 1][j] && !map[i][j - 1]) {
        cache[i][j][1] += cache[i - 1][j - 1][0];
        cache[i][j][1] += cache[i - 1][j - 1][1];
        cache[i][j][1] += cache[i - 1][j - 1][2];
      }
      if (InRange(i - 1, j)) {
        cache[i][j][2] += cache[i - 1][j][1];
        cache[i][j][2] += cache[i - 1][j][2];
      }
    }
  }
  return cache[N - 1][N - 1][0] + cache[N - 1][N - 1][1] +
         cache[N - 1][N - 1][2];
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int x;
      scanf("%d", &x);
      map[i][j] = (x == 1);
    }
  }

  printf("%d\n", Solve());
  return 0;
}