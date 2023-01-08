// 시험 점수
// https://www.acmicpc.net/problem/5596

#include <stdio.h>

int main() {
  int ans = 0;
  for (int i = 0; i < 2; ++i) {
    int local_ans = 0;
    for (int j = 0; j < 4; ++j) {
      int x;
      scanf("%d", &x);
      local_ans += x;
    }
    ans = ans < local_ans ? local_ans : ans;
  }
  printf("%d\n", ans);
  return 0;
}