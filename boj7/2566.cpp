// 최댓값
// https://www.acmicpc.net/problem/2566

#include <stdio.h>

int main() {
  int x, mv, r, c;
  mv = 0;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d", &x);
      if (x > mv) {
        mv = x;
        r = i + 1;
        c = j + 1;
      }
    }
  }

  printf("%d\n%d %d\n", mv, r, c);
  return 0;
}
