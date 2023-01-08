// 행렬
// https://www.acmicpc.net/problem/1080

#include <stdio.h>

int N, M;
char input[52];

bool map[50][50];
bool ref_map[50][50];

int Solve() {
  int ans = 0;
  for (int i = 0; i < N - 2; ++i) {
    for (int j = 0; j < M - 2; ++j) {
      if (map[i][j] == ref_map[i][j]) continue;
      ans++;
      for (int ii = i; ii < i + 3; ++ii) {
        for (int jj = j; jj < j + 3; ++jj) {
          map[ii][jj] = !map[ii][jj];
        }
      }
    }
  }

  for (int i = 0; ans != -1 && i < N; ++i) {
    for (int j = 0; ans != -1 && j < M; ++j) {
      if (map[i][j] != ref_map[i][j]) ans = -1;
    }
  }

  return ans;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int n = 0; n < N; ++n) {
    scanf("%s", input);
    for (int m = 0; m < M; ++m) map[n][m] = input[m] == '1';
  }

  for (int n = 0; n < N; ++n) {
    scanf("%s", input);
    for (int m = 0; m < M; ++m) ref_map[n][m] = input[m] == '1';
  }

  printf("%d\n", Solve());
  return 0;
}