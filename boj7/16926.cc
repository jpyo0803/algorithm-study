// 배열 돌리기 1
// https://www.acmicpc.net/problem/16926

#include <stdio.h>

int N, M, R;

int A[300][300];
int temp_layer[1200];
int layer = 1;
void Solve(int i0, int j0, int i1, int j1, int r) {
  int n = i1 - i0, m = j1 - j0;
  if (n == 0 || m == 0) return;

  int num_element = 2 * (n + m) - 4;
  int rr = r % num_element;

  int i = i0, j = j0;
  for (int k = 0; k < num_element; k++) {
    temp_layer[k] = A[i][j];

    if (j == j0 && i < i1 - 1)
      i++;
    else if (i == i1 - 1 && j < j1 - 1)
      j++;
    else if (j == j1 - 1 && i > i0)
      i--;
    else
      j--;
  }

  if (rr < n - 1) {
    i = i0 + rr;
    j = j0;
  } else if (rr < n + m - 2) {
    i = i1 - 1;
    j = j0 + rr - (n - 1);
  } else if (rr < n + m - 1 + n - 2) {
    i = i1 - 1 - (rr - (n + m - 2));
    j = j1 - 1;
  } else {
    i = i0;
    j = j1 - 1 - (rr - (n + m - 1 + n - 2));
  }

  for (int k = 0; k < num_element; k++) {
    A[i][j] = temp_layer[k];

    if (j == j0 && i < i1 - 1)
      i++;
    else if (i == i1 - 1 && j < j1 - 1)
      j++;
    else if (j == j1 - 1 && i > i0)
      i--;
    else
      j--;
  }

  Solve(i0 + 1, j0 + 1, i1 - 1, j1 - 1, r);
}

int main() {
  scanf("%d%d%d", &N, &M, &R);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  Solve(0, 0, N, M, R);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }

  return 0;
}
