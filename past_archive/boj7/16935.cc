// 배열 돌리기 3
// https://www.acmicpc.net/problem/16935

#include <stdio.h>

#include <algorithm>

int N, M, R;

int A[100][100];
int tA[100][100];

void Swap(int& x, int& y) {
  int tmp = x;
  x = y;
  y = tmp;
}

void FlipUpAndDown() {
  int half_n = N / 2;
  for (int i = 0; i < half_n; i++) {
    for (int j = 0; j < M; j++) {
      Swap(A[i][j], A[N - 1 - i][j]);
    }
  }
}

void FlipLeftAndRight() {
  int half_m = M / 2;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < half_m; j++) {
      Swap(A[i][j], A[i][M - 1 - j]);
    }
  }
}

void RotateRight90() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      tA[j][N - 1 - i] = A[i][j];
    }
  }
  Swap(N, M);
  std::swap(A, tA);
}

void RotateLeft90() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      tA[M - 1 - j][i] = A[i][j];
    }
  }
  Swap(N, M);
  std::swap(A, tA);
}

void RotateRightPartial90() {
  int half_n = N / 2, half_m = M / 2;
  for (int k = 0; k < 4; k++) {
    for (int i = 0; i < half_n; i++) {
      for (int j = 0; j < half_m; j++) {
        int si, sj, di, dj;
        if (k == 0)
          si = 0, sj = 0, di = 0, dj = half_m;
        else if (k == 1)
          si = 0, sj = half_m, di = half_n, dj = half_m;
        else if (k == 2)
          si = half_n, sj = half_m, di = half_n, dj = 0;
        else
          si = half_n, sj = 0, di = 0, dj = 0;
        tA[di + i][dj + j] = A[si + i][sj + j];
      }
    }
  }
  std::swap(A, tA);
}

void RotateLeftPartial90() {
  int half_n = N / 2, half_m = M / 2;
  for (int k = 0; k < 4; k++) {
    for (int i = 0; i < half_n; i++) {
      for (int j = 0; j < half_m; j++) {
        int si, sj, di, dj;
        if (k == 0)
          si = 0, sj = 0, di = half_n, dj = 0;
        else if (k == 1)
          si = half_n, sj = 0, di = half_n, dj = half_m;
        else if (k == 2)
          si = half_n, sj = half_m, di = 0, dj = half_m;
        else
          si = 0, sj = half_m, di = 0, dj = 0;
        tA[di + i][dj + j] = A[si + i][sj + j];
      }
    }
  }
  std::swap(A, tA);
}

void PrintArray() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
}

int main() {
  scanf("%d%d%d", &N, &M, &R);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  for (int i = 0; i < R; i++) {
    int r;
    scanf("%d", &r);
    switch (r) {
      case 1:
        FlipUpAndDown();
        break;
      case 2:
        FlipLeftAndRight();
        break;
      case 3:
        RotateRight90();
        break;
      case 4:
        RotateLeft90();
        break;
      case 5:
        RotateRightPartial90();
        break;
      case 6:
        RotateLeftPartial90();
        break;
    }
  }

  PrintArray();

  return 0;
}
