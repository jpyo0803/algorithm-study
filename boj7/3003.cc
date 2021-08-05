// 킹, 퀸, 룩, 비숍, 나이트, 폰
// https://www.acmicpc.net/problem/3003

#include <stdio.h>

const int arr[6] = {1, 1, 2, 2, 2, 8};

int main() {
  for (int i = 0; i < 6; i++) {
    int x;
    scanf("%d", &x);
    printf("%d ", arr[i] - x);
  }
  printf("\n");
  return 0;
}
