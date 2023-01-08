//
// Plug
// Problem: https://www.acmicpc.net/problem/2010
//

#include <cstdio>
int N, e;
int main() {
  scanf("%d", &N);
  int sum{-(N - 1)};
  for (int i = 0; i < N; i++) {
    scanf("%d", &e);
    sum += e;
  }
  printf("%d", sum);

  return 0;
}
