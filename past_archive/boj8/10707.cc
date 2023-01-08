// 수도요금
// https://www.acmicpc.net/problem/10707

#include <stdio.h>

int A, B, C, D, P;

int Min(int x, int y) { return x < y ? x : y; }

int main() {
  scanf("%d%d%d%d%d", &A, &B, &C, &D, &P);
  printf("%d\n", Min(A * P, B + (C < P ? P - C : 0) * D));
  return 0;
}
