// 싱기한 네자리 숫자
// https://www.acmicpc.net/problem/6679

#include <stdio.h>

int SumBase(int x, int base) {
  int sum = 0;
  while (x > 0) {
    sum += x % base;
    x /= base;
  }
  return sum;
}

int main() {
  for (int i = 1000; i < 10000; ++i) {
    if (SumBase(i, 10) == SumBase(i, 12) && SumBase(i, 12) == SumBase(i, 16)) {
      printf("%d\n", i);
    }
  }
  return 0;
}