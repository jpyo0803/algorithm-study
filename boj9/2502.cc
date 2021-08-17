// 떡 먹는 호랑이
// https://www.acmicpc.net/problem/2502

#include <stdio.h>

int D, K;

bool Solve(int a, int b) {
  for (int i = 3; i <= D; ++i) {
    int tmp = b;
    b = a + b;
    a = tmp;
  }
  return b == K;
}

int main() {
  scanf("%d%d", &D, &K);

  for (int a = 1; a <= K; ++a) {
    for (int b = a; b <= K; ++b) {
      if (Solve(a, b)) {
        printf("%d\n%d\n", a, b);
        return 0;
      }
    }
  }
  return 0;
}