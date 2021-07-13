// 점프 점프
// https://www.acmicpc.net/problem/11060

#include <stdio.h>

constexpr int kInf = 987654321;

int N;

int A[1000];
int cache[1000];

int Min(int x, int y) { return x < y ? x : y; }

int Solve() {
  cache[0] = 0;

  for (int n = 0; n < N; ++n) {
    for (int step = 1; step <= A[n]; ++step) {
      int next_step = n + step;
      if (next_step >= N) break;
      cache[next_step] = Min(cache[next_step], cache[n] + 1);
    }
  }
  return (cache[N - 1] == kInf ? -1 : cache[N - 1]);
}

int main() {
  scanf("%d", &N);
  for (int n = 0; n < N; ++n) {
    scanf("%d", &A[n]);
    cache[n] = kInf;
  }

  printf("%d\n", Solve());

  return 0;
}