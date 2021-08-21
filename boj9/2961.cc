// 도영이가 만든 맛있는 음식
// https://www.acmicpc.net/problem/2961

#include <stdint.h>
#include <stdio.h>

int N;

int sour[11];
int bitter[11];
bool used[11];

int64_t ans = 1'000'000'000 - 1;

int64_t Abs(int64_t x) { return x < 0 ? -x : x; }

int64_t Min(int64_t x, int64_t y) { return x < y ? x : y; }

void Solve(int n, int last, int64_t rs, int64_t rb) {
  if (n == N) return;

  for (int i = last + 1; i < N; ++i) {
    if (used[i]) continue;
    used[i] = true;
    int64_t nrs = rs * sour[i];
    int64_t nrb = rb + bitter[i];
    if (Abs(nrs - nrb) < 1'000'000'000) {
      ans = Min(ans, Abs(nrs - nrb));
      Solve(n + 1, i, rs * sour[i], rb + bitter[i]);
    }
    used[i] = false;
  }
}

int main() {
  scanf("%d", &N);
  for (int n = 0; n < N; ++n) {
    scanf("%d%d", &sour[n], &bitter[n]);
  }

  Solve(0, -1, 1, 0);
  printf("%lld\n", ans);
  return 0;
}