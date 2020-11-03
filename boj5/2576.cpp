//
// 홀수
// Link: https://www.acmicpc.net/problem/2576
//

#include <cstdio>

int main() {
  int sum = 0;
  int min = 987654321;
  for (int i = 0; i < 7; i++) {
    int x;
    scanf("%d", &x);
    if (x % 2) {
      sum += x;
      min = (x < min ? x : min);
    }
  }
  if (min == 987654321) printf("-1\n");
  else printf("%d\n%d\n", sum, min);
  return 0;
}