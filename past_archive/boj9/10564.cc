// 팔굽혀펴기
// https://www.acmicpc.net/problem/10564

#include <stdio.h>

int T, N, M;

bool cache[5001][5001];
int scores[10];

int Max(int x, int y) { return x < y ? y : x; }

void Solve(int n, int x) {
  if (n > N) return;
  if (cache[n][x]) return;
  cache[n][x] = true;

  for (int i = 0; i < M; ++i) {
    Solve(n + x + scores[i], x + scores[i]);
  }
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d%d", &N, &M);
    for (int m = 0; m < M; ++m) {
      scanf("%d", &scores[m]);
    }

    for (int i = 0; i <= N; ++i) {
      for (int j = 0; j <= N; ++j) {
        cache[i][j] = false;
      }
    }

    Solve(0, 0);

    int ans = -1;
    for (int x = 1; x <= N; ++x) {
      if (cache[N][x]) ans = Max(ans, x);
    }
    printf("%d\n", ans);
  }

  return 0;
}