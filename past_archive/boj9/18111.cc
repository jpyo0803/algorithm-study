// 마인 크래프트
// https://www.acmicpc.net/problem/18111

#include <stdio.h>

int N, M, B;
int map[510][510];

int min_t = 987654321;
int max_h = 0;

void Solve() {
  for (int h = 0; h <= 256; ++h) {
    int t = 0;
    int b = B;
    int need = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (map[i][j] > h) {
          int diff = map[i][j] - h;
          b += diff;
          t += diff * 2;
        } else if (map[i][j] < h) {
          int diff = h - map[i][j];
          need += diff;
        }
      }
    }

    if (b >= need) {
      t += need;
      if (t <= min_t) {
        min_t = t;
        max_h = h;
      }
    }
  }
}

int main() {
  scanf("%d%d%d", &N, &M, &B);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      scanf("%d", &map[i][j]);
    }
  }

  Solve();

  printf("%d %d\n", min_t, max_h);
  return 0;
}