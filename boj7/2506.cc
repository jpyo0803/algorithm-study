// 점수 계산
// https://www.acmicpc.net/problem/2506

#include <stdio.h>

int N;

int main() {
  scanf("%d", &N);
  int total = 0;
  int consecutive_right = 0;
  for (int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    if (x) {
      consecutive_right++;
      total += consecutive_right;
    } else {
      consecutive_right = 0;
    }
  }
  printf("%d\n", total);
  return 0;
}
