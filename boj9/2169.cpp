// 로봇 조종하기
// https://www.acmicpc.net/problem/2169

#include <stdio.h>

constexpr int kNegInf = -987654321;

int N, M;

int value[1000][1000];
int cache[1000][1000][3];
bool visited[1000][1000];

int d[3][2] = {{0, 1}, {0, -1}, {-1, 0}};

bool InRange(int i, int j) { return i >= 0 && i < N && j >= 0 && j < M; }

int Max(int x, int y) { return x < y ? y : x; }

int Solve(int i, int j, int dir) {
  if (i == 0 && j == 0) return value[0][0];
  int& ret = cache[i][j][dir];
  if (ret != kNegInf) return ret;

  visited[i][j] = true;
  for (int k = 0; k < 3; ++k) {
    int ni = i + d[k][0];
    int nj = j + d[k][1];

    if (!InRange(ni, nj) || visited[ni][nj]) continue;
    ret = Max(ret, Solve(ni, nj, k) + value[i][j]);
  }
  visited[i][j] = false;
  return ret;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      scanf("%d", &value[i][j]);
      for (int k = 0; k < 3; ++k) {
        cache[i][j][k] = -987654321;
      }
    }
  }

  visited[N - 1][M - 1] = true;
  int ans = kNegInf;
  for (int i = 0; i < 3; ++i) {
    ans = Max(ans, Solve(N - 1, M - 1, i));
  }
  printf("%d\n", ans);
  return 0;
}