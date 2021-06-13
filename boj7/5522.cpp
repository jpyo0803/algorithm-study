// 카드
// https://www.acmicpc.net/problem/5522

#include <stdio.h>

int main() {
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    int x;
    scanf("%d", &x);
    ans += x;
  }
  printf("%d\n", ans);
  return 0;
}
