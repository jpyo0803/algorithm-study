// 더하기
// https://www.acmicpc.net/problem/9085

#include <stdio.h>

int T, N, x;

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d", &N);
    int ans = 0;
    for (int i = 0; i < N; i++) {
      scanf("%d", &x);
      ans += x;
    }
    printf("%d\n", ans);
  }
  return 0;
}
