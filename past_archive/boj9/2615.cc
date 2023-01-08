// 오목
// https://www.acmicpc.net/problem/2615

#include <stdio.h>

int board[19][19];
bool check[19][19][4];  // 0 = right, 1 = down, 2 = right down
int d[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};

bool InRange(int i, int j) { return i >= 0 && i < 19 && j >= 0 && j < 19; }

int CheckVictory(int i, int j) {
  int success = 0;
  for (int k = 0; k < 4; ++k) {
    if (check[i][j][k]) continue;
    int l = 0;
    while (l < 6) {
      int ni = d[k][0] * l + i;
      int nj = d[k][1] * l + j;
      if (!InRange(ni, nj)) break;
      if (board[ni][nj] == board[i][j]) {
        ++l;
        check[ni][nj][k] = true;
      } else {
        break;
      }
    }
    if (l == 5) {
      success = board[i][j];
    }
  }
  return success;
}

void Solve() {
  int which = -1, ai = 30, aj = 30;
  for (int i = 0; i < 19; ++i) {
    for (int j = 0; j < 19; ++j) {
      int result = CheckVictory(j, i);
      if (result > 0) {
        if (j < aj) {
          which = result;
          ai = i;
          aj = j;
        }
      }
    }
  }
  if (which == -1)
    printf("0\n");
  else
    printf("%d\n%d %d\n", which, aj + 1, ai + 1);
}

int main() {
  for (int i = 0; i < 19; ++i) {
    for (int j = 0; j < 19; ++j) {
      scanf("%d", &board[i][j]);
    }
  }

  Solve();

  return 0;
}
