// 약수의 합
// https://www.acmicpc.net/problem/17425

#include <stdio.h>

int T, N;

long long int cache[1000001];

void PreCompute() {
  cache[1] = 1;
  for (int i = 2; i <= 1000000; i++) {
    for (int j = 1; i * j <= 1000000; j++) {
      cache[i * j] += i;
    }
    cache[i] += cache[i - 1] + 1;
  }
}

int main() {
  PreCompute();

  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d", &N);
    printf("%lld\n", cache[N]);
  }
  return 0;
}
