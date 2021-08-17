// 합구하기
// https://www.acmicpc.net/problem/11441

#include <stdio.h>

int N, M;
int sum_arr[100'010];

int main() {
  scanf("%d", &N);
  for (int n = 1; n <= N; ++n) {
    scanf("%d", &sum_arr[n]);
    sum_arr[n] += sum_arr[n - 1];
  }
  scanf("%d", &M);
  for (int m = 0; m < M; ++m) {
    int s, e;
    scanf("%d%d", &s, &e);
    printf("%d\n", sum_arr[e] - sum_arr[s - 1]);
  }
  return 0;
}