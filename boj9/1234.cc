// 크리스마스 트리
// https://www.acmicpc.net/problem/1234

#include <stdint.h>
#include <stdio.h>

int N, R, G, B;

int64_t cache[11][101][101][101];
int64_t fact_cache[11];

int64_t Factorial(int n) {
  if (n <= 1) return 1;
  int64_t& ret = fact_cache[n];
  if (ret != 0) return ret;
  return ret = n * Factorial(n - 1);
}

int64_t Solve(int n, int r, int g, int b) {
  if (r < 0 || g < 0 || b < 0) return 0;
  if (n == 1) {
    int64_t tmp = 0;
    if (r > 0) ++tmp;
    if (g > 0) ++tmp;
    if (b > 0) ++tmp;
    return tmp;
  }

  int64_t& ret = cache[n][r][g][b];
  if (ret != -1) return ret;
  ret = 0;

  ret += Solve(n - 1, r - n, g, b);
  ret += Solve(n - 1, r, g - n, b);
  ret += Solve(n - 1, r, g, b - n);

  if (n % 2 == 0) {
    int64_t half_n = n / 2;
    ret += Solve(n - 1, r - half_n, g - half_n, b) * Factorial(n) /
           Factorial(half_n) / Factorial(half_n);
    ret += Solve(n - 1, r - half_n, g, b - half_n) * Factorial(n) /
           Factorial(half_n) / Factorial(half_n);
    ret += Solve(n - 1, r, g - half_n, b - half_n) * Factorial(n) /
           Factorial(half_n) / Factorial(half_n);
  }

  if (n % 3 == 0) {
    int64_t third_n = n / 3;
    ret += Solve(n - 1, r - third_n, g - third_n, b - third_n) *
           (Factorial(n) / Factorial(third_n)) / Factorial(third_n) /
           Factorial(third_n);
  }
  return ret;
}

int main() {
  scanf("%d%d%d%d", &N, &R, &G, &B);
  for (int n = 0; n <= N; ++n) {
    for (int r = 0; r <= R; ++r) {
      for (int g = 0; g <= G; ++g) {
        for (int b = 0; b <= B; ++b) {
          cache[n][r][g][b] = -1;
        }
      }
    }
  }

  printf("%lld\n", Solve(N, R, G, B));

  return 0;
}