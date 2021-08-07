// 줄세우기
// https://www.acmicpc.net/problem/2631

#include <stdio.h>

int N;
int arr[201];
int cache[201];

int Solve() {
  int global_max = 0;
  for (int i = 0; i < N; ++i) {
    int j = i - 1;
    int local_max = 0;
    while (j >= 0) {
      if (arr[j] < arr[i] && local_max < cache[j]) {
        local_max = cache[j];
      }
      --j;
    }
    cache[i] = local_max + 1;
    global_max = global_max < cache[i] ? cache[i] : global_max;
  }
  return global_max;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &arr[i]);
  }

  printf("%d\n", N - Solve());

  return 0;
}