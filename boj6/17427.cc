// 약수의 합2
// https://www.acmicpc.net/problem/17427

#include <inttypes.h>
#include <stdio.h>

int N;

int64_t Solve(int n) {
  int64_t ret = 0;
  for (int i = 1; i <= n; i++) ret += (n / i) * i;
  return ret;
}

int main() {
  scanf("%d", &N);
  printf("%" PRId64 "\n", Solve(N));
  return 0;
}
