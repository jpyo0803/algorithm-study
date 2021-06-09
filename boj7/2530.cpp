// 인공지능 시계
// https://www.acmicpc.net/problem/2530

#include <stdio.h>

int A, B, C, D;

int main() {
  scanf("%d%d%d%d", &A, &B, &C, &D);

  int ts = A * 3600 + B * 60 + C + D;

  int h = ts / 3600;
  ts -= h * 3600;
  int m = ts / 60;
  ts -= m * 60;
  int s = ts;

  h %= 24;
  m %= 60;

  printf("%d %d %d\n", h, m, s);
  return 0;
}
