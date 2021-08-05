// 방학 숙제
// https://www.acmicpc.net/problem/5532

#include <stdio.h>

int L, A, B, C, D;

int Max(int x, int y) { return x < y ? y : x; }

int main() {
  scanf("%d%d%d%d%d", &L, &A, &B, &C, &D);
  int need_a = 0, need_b = 0;
  need_a += A / C;
  need_a += A % C > 0 ? 1 : 0;
  need_b += B / D;
  need_b += B % D > 0 ? 1 : 0;
  printf("%d\n", L - Max(need_a, need_b));
  return 0;
}
