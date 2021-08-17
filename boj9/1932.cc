// 정수 삼각형
// https://www.acmicpc.net/problem/1932

#include <stdio.h>

int N;

int arr[510][510];
int cache[510][510];

bool InRange(int r, int c) { return 0 <= c && c <= r; }

int Max(int x, int y) { return x < y ? y : x; }

int Solve(int r, int c) {
  if (r < 0) return 0;
  if (!InRange(r, c)) return 0;

  int& ret = cache[r][c];
  if (ret != -1) return ret;

  ret = Max(Solve(r - 1, c - 1), Solve(r - 1, c)) + arr[r][c];
  return ret;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= i; ++j) {
      scanf("%d", &arr[i][j]);
      cache[i][j] = -1;
    }
  }

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ans = Max(ans, Solve(N - 1, i));
  }

  printf("%d\n", ans);
  return 0;
}