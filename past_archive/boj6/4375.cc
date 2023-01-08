// 1
// https://www.acmicpc.net/problem/4375

#include <stdio.h>

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int count = 1;
    int num = 1;
    while (true) {
      if (num % n == 0) break;
      num = (num % n) * 10 + 1;
      count++;
    }
    printf("%d\n", count);
  }

  return 0;
}
