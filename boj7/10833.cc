// 사과
// https://www.acmicpc.net/problem/10833

#include <stdio.h>

int N, s, a;

int main() {
  scanf("%d", &N);

  int rem = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &s, &a);
    rem += a % s;
  }

  printf("%d\n", rem);
  return 0;
}
