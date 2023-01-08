// 심부름 가는 길
// https://www.acmicpc.net/problem/5554

#include <stdio.h>

int main() {
  int total_seconds = 0;
  for (int i = 0; i < 4; i++) {
    int sec;
    scanf("%d", &sec);
    total_seconds += sec;
  }

  int m = total_seconds / 60;
  total_seconds -= m * 60;
  int s = total_seconds;

  printf("%d\n%d\n", m, s);
  return 0;
}
