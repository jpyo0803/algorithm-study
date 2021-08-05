// 중앙 이동 알고리즘
// https://www.acmicpc.net/problem/2903

#include <stdio.h>

int N;

int main() {
  scanf("%d", &N);
  int base = 2;
  for (int i = 0; i < N; i++) {
    base = base * 2 - 1;
  }
  printf("%d\n", base * base);
  return 0;
}