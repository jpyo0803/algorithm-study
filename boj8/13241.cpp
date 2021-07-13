// 최소공배수
// https://www.acmicpc.net/problem/13241

#include <stdio.h>

long long Gcd(long long x, long long y) {
  if (y == 0) return x;
  return Gcd(y, x % y);
}

long long Lcm(long long x, long long y) { return x * y / Gcd(x, y); }

int A, B;

int main() {
  scanf("%d%d", &A, &B);
  printf("%lld\n", Lcm(A, B));
  return 0;
}