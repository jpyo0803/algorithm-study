// 숫자 놀이
// https://www.acmicpc.net/problem/12971

#include <stdio.h>

int P1, P2, P3, X1, X2, X3;

int main() {
  scanf("%d%d%d%d%d%d", &P1, &P2, &P3, &X1, &X2, &X3);

  int p = P1 * P2 * P3;
  int ans = -1;
  for (int n = 1; n <= p; n++) {
    if (n % P1 == X1 && n % P2 == X2 && n % P3 == X3) {
      ans = n;
      break;
    }
  }
  printf("%d\n", ans);

  return 0;
}
