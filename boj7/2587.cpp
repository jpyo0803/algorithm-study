// 대표값2
// https://www.acmicpc.net/problem/2587

#include <stdio.h>

int x;

int main() {
  int mean = 0;
  int big1 = 0, big2 = 0, big3 = 0;
  for (int i = 0; i < 5; i++) {
    scanf("%d", &x);
    mean += x;
    if (x > big1) {
      big3 = big2;
      big2 = big1;
      big1 = x;
    } else if (x > big2) {
      big3 = big2;
      big2 = x;
    } else if (x > big3) {
      big3 = x;
    }
  }
  printf("%d\n%d\n", mean / 5, big3);
  return 0;
}
