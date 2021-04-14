//
// Hashing
// Link: https://www.acmicpc.net/problem/15829
//

#include <inttypes.h>
#include <stdio.h>

constexpr int64_t M = 1234567891;
constexpr int64_t r = 31;

int N;
char input[51];

int64_t Pow(int64_t base, int exp) {
  if (exp == 0) return 1;
  if (exp == 1) return base;
  int64_t res = Pow(base, exp / 2);
  res = (res * res) % M;
  if (exp % 2) {
    res *= base;
    res %= M;
  }
  return res;
}

int main() {
  scanf("%d%s", &N, input);

  int64_t ans = 0;
  for (int i = 0; i < N; i++) {
    ans += (static_cast<int64_t>(input[i] - 'a') + 1) * Pow(r, i);
    ans %= M;
  }
  printf("%" PRId64 "\n", ans);

  return 0;
}
