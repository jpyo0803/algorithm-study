//
// 검증수
// Link: https://www.acmicpc.net/problem/2475
//

#include <cstdio>
int ans = 0;
int main() {
  for (int i = 0; i < 5; i++) {
    int x;
    scanf("%d", &x);
    ans += x * x;
  }
  printf("%d\n", ans % 10);
}