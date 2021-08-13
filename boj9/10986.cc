// 나머지 합
// https://www.acmicpc.net/problem/10986

#include <stdint.h>
#include <stdio.h>

int N, M;

int64_t arr[1000010];
int64_t count[1010];

int main() {
  scanf("%d%d", &N, &M);

  for (int n = 1; n <= N; ++n) {
    scanf("%lld", &arr[n]);
    arr[n] += arr[n - 1];
    arr[n] %= M;
    ++count[arr[n]];
  }

  int64_t ans = count[0];
  for (int i = 0; i < M; ++i) {
    int64_t x = count[i];
    ans += x * (x - 1) / 2;
  }

  printf("%lld\n", ans);

  return 0;
}