// NM과 K (1)
// https://www.acmicpc.net/problem/18290

#include <stdio.h>

int N, M, K;
int board[10][10];
int visited[10][10];
int d[5][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int Max(int x, int y) { return x < y ? y : x; }

bool InRange(int i, int j) { return i >= 0 && i < N && j >= 0 && j < M; }

int ans = -987654321;

void Solve(int i, int j, int nth, int sum) {
  if (nth == K) {
    ans = Max(ans, sum);
    return;
  }

  int ni = i, nj = j;
  while (ni < N) {
    if (visited[ni][nj] == 0) {
      for (int k = 0; k < 5; k++) {
        int ti = ni + d[k][0];
        int tj = nj + d[k][1];

        if (!InRange(ti, tj)) continue;
        visited[ti][tj]++;
      }

      Solve(ni, nj, nth + 1, sum + board[ni][nj]);

      for (int k = 0; k < 5; k++) {
        int ti = ni + d[k][0];
        int tj = nj + d[k][1];

        if (!InRange(ti, tj)) continue;
        visited[ti][tj]--;
      }
    }

    nj++;
    if (nj == M) {
      nj = 0;
      ni++;
    }
  }
}

int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  Solve(0, 0, 0, 0);
  printf("%d\n", ans);

  return 0;
}
