// 분수 합
// https://www.acmicpc.net/problem/1735

#include <stdio.h>

int Gcd(int x, int y) {
  if (y == 0) return x;
  return Gcd(y, x % y);
}

int A, B, C, D;

int main() {
  scanf("%d%d%d%d", &A, &B, &C, &D);
  int numerator = A * D + B * C;
  int denominator = B * D;

  int gcd = Gcd(numerator, denominator);
  printf("%d %d\n", numerator / gcd, denominator / gcd);
  return 0;
}
