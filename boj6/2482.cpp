// 색상환
// https://www.acmicpc.net/problem/2482

#include <stdio.h>
#include <string.h>

constexpr int kMod = 1000000003;

int cache[1001][502];
int N, K;

int Solve(int N, int K) {
  for (int n = 2; n <= N; n++) {
    for (int k = 1; k <= N / 2; k++) {
      if (k == 1)
        cache[n][k] = n;
      else
        cache[n][k] = (cache[n - 2][k - 1] + cache[n - 1][k]) % kMod;
    }
  }
  return cache[N][K];
}

int main() {
  scanf("%d%d", &N, &K);
  printf("%d\n", Solve(N, K));
  return 0;
}
