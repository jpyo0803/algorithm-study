// 슈퍼 마리오
// https://www.acmicpc.net/problem/2851

#include <stdio.h>

int Abs(int x) { return x < 0 ? -x : x; }

int main() {
  int sum = 0;
  for (int i = 0; i < 10; ++i) {
    int x;
    scanf("%d", &x);
    int tmp_sum = sum + x;
    int diff = Abs(tmp_sum - 100);
    if (diff < Abs(sum - 100)) {
      sum = tmp_sum;
    } else if (diff == Abs(sum - 100)) {
      if (tmp_sum > sum) {
        sum = tmp_sum;
      }
    } else {
      break;
    }
  }
  printf("%d\n", sum);
  return 0;
}