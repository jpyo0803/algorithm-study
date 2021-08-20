// 초6 수학
// https://www.acmicpc.net/problem/2702

#include <stdio.h>

int T;

int Gcd(int x, int y) {
  if (y == 0) return x;
  return Gcd(y, x % y);
}

int Lcm(int x, int y) {
  int gcd = Gcd(x, y);
  return x * y / gcd;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d %d\n", Lcm(a, b), Gcd(a, b));
  }
  return 0;
}