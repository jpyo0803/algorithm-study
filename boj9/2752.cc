// 세수정렬
// https://www.acmicpc.net/problem/2752

#include <stdio.h>

int main() {
  int l, m, h;
  l = m = h = 0;
  for (int i = 0; i < 3; ++i) {
    int x;
    scanf("%d", &x);
    if (x > h) {
      l = m;
      m = h;
      h = x;
    } else if (x > m) {
      l = m;
      m = x;
    } else {
      l = x;
    }
  }
  printf("%d %d %d\n", l, m, h);
  return 0;
}