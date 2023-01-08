// 파일 옮기기
// https://www.acmicpc.net/problem/11943

#include <stdio.h>

int A, B, C, D;

int Min(int x, int y) { return x < y ? x : y; }

int main() {
  scanf("%d%d%d%d", &A, &B, &C, &D);
  printf("%d", Min(A + D, B + C));
  return 0;
}
