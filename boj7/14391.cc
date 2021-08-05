// 종이조각
// https://www.acmicpc.net/problem/14391

#include <stdio.h>

struct Board {
  bool arr[4][4];
};

int N, M;
int board[4][4];

int Max(int x, int y) { return x < y ? y : x; }
bool InRange(int i, int j) { return i >= 0 && i < N && j >= 0 && j < M; }

int Solve(Board b, int ii, int jj) {
  int i = -1, j = -1;

  int ti = ii, tj = jj;
  while (true) {
    if (tj == M) {
      tj = 0;
      ti++;
    }
    if (ti == N) break;
    if (!b.arr[ti][tj]) {
      i = ti;
      j = tj;
      break;
    }
    tj++;
  }
  if (i == -1) return 0;

  int ret = 0;

  Board nb = b;
  int local_sum = 0;
  for (int k = 0; k < N; k++) {
    if (!InRange(i + k, j)) break;
    if (b.arr[i + k][j]) break;
    local_sum = local_sum * 10 + board[i + k][j];
    nb.arr[i + k][j] = true;
    ret = Max(ret, Solve(nb, i, j + 1) + local_sum);
  }

  nb = b;
  local_sum = 0;
  for (int k = 0; k < M; k++) {
    if (!InRange(i, j + k)) break;
    if (b.arr[i][j + k]) break;
    local_sum = local_sum * 10 + board[i][j + k];
    nb.arr[i][j + k] = true;
    ret = Max(ret, Solve(nb, i + 1, j) + local_sum);
  }
  return ret;
}

int main() {
  scanf("%d%d", &N, &M);

  char line[5];
  for (int i = 0; i < N; i++) {
    scanf("%s", line);
    for (int j = 0; j < M; j++) {
      board[i][j] = line[j] - '0';
    }
  }

  Board b;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      b.arr[i][j] = false;
    }
  }
  printf("%d\n", Solve(b, 0, 0));

  return 0;
}
