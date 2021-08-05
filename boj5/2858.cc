//
// 기숙사 바닥
// Link: https://www.acmicpc.net/problem/2858
//

#include <cstdio>

int R, B, L, W;

void Solve() {
  for (int l = 1; l <= 2501; l++) {
    int w = (R + 4 - 2 * l) / 2;
    if ((l - 2) * (w - 2) == B) {
      L = (l < w ? w : l);
      W = (l < w ? l : w);
      return;
    }
  }
}

int main() {
  scanf("%d%d", &R, &B);
  Solve();
  printf("%d %d\n", L, W);
  return 0;
}