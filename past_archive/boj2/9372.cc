//
// Travel of Sangkeun
// Problem: https://www.acmicpc.net/problem/9372
//

#include <cstdio>
int T, N, M, a, b;
int main() {
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
      scanf("%d%d", &a, &b);
    }
    printf("%d\n", N - 1);
  }
  return 0;
}