// 구간 합 구하기 4
// https://www.acmicpc.net/problem/11659

#include <stdio.h>

int N, M, x, a, b;
int arr[100001];

int main() {
  scanf("%d%d", &N, &M);
  for (int n = 1; n <= N; n++) {
    scanf("%d", &x);
    arr[n] = arr[n - 1] + x;
  }

  for (int m = 0; m < M; m++) {
    scanf("%d%d", &a, &b);
    printf("%d\n", arr[b] - arr[a - 1]);
  }

  return 0;
}
