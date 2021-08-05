// 약수 구하기
// https://www.acmicpc.net/problem/2501

#include <stdio.h>

int N, K;

int main() {
  scanf("%d%d", &N, &K);

  int ans = 0;
  int nth = 0;
  for (int i = N; i > 0; i--) {
    if (N % i == 0) {
      nth++;
      if (nth == K) {
        ans = N / i;
        break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
