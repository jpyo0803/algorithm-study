// 사파리월드
// https://www.acmicpc.net/problem/2420

#include <stdio.h>

long long Abs(long long x) { return x < 0 ? -x : x; }
long long AbsDiff(long long x, long long y) { return Abs(x - y); }

long long N, M;

int main() {
  scanf("%lld%lld", &N, &M);
  printf("%lld\n", AbsDiff(N, M));
  return 0;
}
