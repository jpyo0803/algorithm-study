// 파티가 끝나고 난뒤
// https://www.acmicpc.net/problem/2845

#include <stdio.h>

int L, P, x;

int main() {
  scanf("%d%d", &L, &P);
  int lp = L * P;
  for (int i = 0; i < 5; i++) {
    scanf("%d", &x);
    printf("%d ", x - lp);
  }
  return 0;
}
