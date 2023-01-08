// 주사위 세개
// https://www.acmicpc.net/problem/2480

#include <stdio.h>

int x, y, z;

int main() {
  scanf("%d%d%d", &x, &y, &z);
  if (x == y && y == z)
    printf("%d\n", 10000 + x * 1000);
  else if (x == y)
    printf("%d\n", 1000 + x * 100);
  else if (y == z)
    printf("%d\n", 1000 + y * 100);
  else if (x == z)
    printf("%d\n", 1000 + z * 100);
  else {
    int max = 1;
    max = x < y ? y : x;
    max = max < z ? z : max;
    printf("%d\n", max * 100);
  }
  return 0;
}
