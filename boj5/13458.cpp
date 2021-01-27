//
// 시험 감독
// Link: https://www.acmicpc.net/problem/13458
//

#include <cstdint>
#include <cstdio>

int N;
int A[1000000];
int B, C;

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);
  scanf("%d%d", &B, &C);

  uint64_t ans = 0;
  for (int i = 0; i < N; i++) {
    ans++;
    A[i] -= B;
    if (A[i] > 0) {
      ans += A[i] / C;
      if (A[i] % C) ans++;
    }
  }
  printf("%llu\n", ans);
  return 0;
}