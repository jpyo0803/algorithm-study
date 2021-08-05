// 돌 게임 2
// https://www.acmicpc.net/problem/9656

#include <stdio.h>

bool cache[1001];

bool Solve(int N) {
  cache[2] = true;
  for (int i = 4; i <= N; i++) {
    cache[i] = !cache[i - 1] | !cache[i - 3];
  }
  return cache[N];
}

int main() {
  int N;
  scanf("%d", &N);
  if (Solve(N))
    printf("SK\n");
  else
    printf("CY\n");

  return 0;
}
