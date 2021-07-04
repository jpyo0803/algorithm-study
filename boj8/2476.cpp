// 주사위 게임
// https://www.acmicpc.net/problem/2476

#include <stdio.h>

int N, x, y, z;

int Max(int x, int y) { return x < y ? y : x; }

int main() {
  scanf("%d", &N);

  int ans = 0;
  for (int n = 0; n < N; ++n) {
    scanf("%d%d%d", &x, &y, &z);
    int local_ans = 0;
    if (x == y && y == z) {
      local_ans = 10000 + x * 1000; 
    } else if (x != y && y != z && x != z) {
      local_ans = Max(x, Max(y, z)) * 100;
    } else {
      if (x == y) {
        local_ans = 1000 + x * 100;
      } else if (y == z) {
        local_ans = 1000 + y * 100;
      } else {
        local_ans = 1000 + x * 100;
      }
    }
    ans = Max(ans, local_ans);
  }
  printf("%d\n", ans);
  return 0;
}