//
// 달팽이
// Link: https://www.acmicpc.net/problem/1913
//

#include <stdio.h>

int N, target;

int table[1000][1000];

int main() {
  scanf("%d%d", &N, &target);
  int NN = N * N;

  int ii, jj;
  ii = jj = N / 2;
  for (int layer = 0; layer < (N + 1) / 2; layer++) {
    int num_fill = N - 1 - (2 * layer);
    int i, j;
    i = j = layer;
    for (int k = 0; k < num_fill; k++) {
      if (NN == target) {
        ii = i + k;
        jj = j;
      }
      table[i + k][j] = NN--;
    }

    i = N - 1 - layer;
    j = layer;
    for (int k = 0; k < num_fill; k++) {
      if (NN == target) {
        ii = i;
        jj = j + k;
      }
      table[i][j + k] = NN--;
    }

    i = j = N - 1 - layer;
    for (int k = 0; k < num_fill; k++) {
      if (NN == target) {
        ii = i - k;
        jj = j;
      }
      table[i - k][j] = NN--;
    }

    i = layer;
    j = N - 1 - layer;
    for (int k = 0; k < num_fill; k++) {
      if (NN == target) {
        ii = i;
        jj = j - k;
      }
      table[i][j - k] = NN--;
    }
  }
  table[N / 2][N / 2] = 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }
  printf("%d %d\n", ii + 1, jj + 1);
  return 0;
}
