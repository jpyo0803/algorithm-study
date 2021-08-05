// 별 찍기 - 11
// https://www.acmicpc.net/problem/2448

#include <stdio.h>

int N;
bool board[3100][6200];

void GenerateStar(int i, int j) {
  board[i][j] = true;
  board[i + 1][j - 1] = board[i + 1][j + 1] = true;
  for (int k = -2; k < 3; ++k) {
    board[i + 2][j + k] = true;
  }
}

void Solve(int n, int i, int j) {
  if (n == 3) {
    GenerateStar(i - 3, j);
    return;
  }

  int half_n = n / 2;
  Solve(n / 2, i - half_n, j);
  Solve(n / 2, i, j - half_n);
  Solve(n / 2, i, j + half_n);
}

int main() {
  scanf("%d", &N);
  Solve(N, N, (2 * N - 1) / 2);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 2 * N; ++j) {
      printf("%c", board[i][j] ? '*' : ' ');
    }
    printf("\n");
  }
  return 0;
}