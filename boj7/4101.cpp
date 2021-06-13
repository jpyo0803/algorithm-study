// 크냐?
// https://www.acmicpc.net/problem/4101

#include <stdio.h>

int a, b;

int main() {
  scanf("%d%d", &a, &b);
  while (a != 0 && b != 0) {
    if (a > b)
      printf("Yes\n");
    else
      printf("No\n");
    scanf("%d%d", &a, &b);
  }
  return 0;
}
