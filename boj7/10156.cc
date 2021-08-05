// 과자
// https://www.acmicpc.net/problem/10156

#include <stdio.h>

int K, N, M;

int main() {
  scanf("%d%d%d", &K, &N, &M);
  int ans = 0;
  ans = ans < K * N - M ? K * N - M : ans;
  printf("%d\n", ans);
  return 0;
}
