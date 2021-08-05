// 연속 합 2
// https://www.acmicpc.net/source/18073645

#include <stdio.h>

int seq[100000];
int cache[100000][2];  // 0 = used all, 1 = discarded one

int N;

int Max(int x, int y) { return x < y ? y : x; }

int Solve(int n) {
  cache[0][0] = seq[0];
  cache[0][1] = 0;
  int ans = seq[0];

  for (int i = 1; i < n; i++) {
    cache[i][0] = Max(seq[i], cache[i - 1][0] + seq[i]);
    cache[i][1] = Max(cache[i - 1][1] + seq[i], cache[i - 1][0]);
    ans = Max(ans, cache[i][0]);
    ans = Max(ans, cache[i][1]);
  }
  return ans;
}

int main() {
  scanf("%d", &N);
  for (int n = 0; n < N; n++) scanf("%d", &seq[n]);
  printf("%d\n", Solve(N));
  return 0;
}
