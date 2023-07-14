//
// Square Matrix Multiplication
// Naive way = O(N^3)
// Strassen's way = O(N^lg(7))
//

#include <iomanip>
#include <iostream>
#include <matrix.hpp>
#include <random_number_generator.hpp>

using namespace std;
const int N{8};
int A[N][N];
int B[N][N];
int C_naive[N][N];
int C_dnc[N][N];

int p1[N][N];
int p2[N][N];
int p3[N][N];
int p4[N][N];
int p5[N][N];
int p6[N][N];
int p7[N][N];

void fill_rn(int arr[][N], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = get_random_number(0, 10);
    }
  }
}

void print_matrix(int arr[][N], int n) {
  for (int i = 0; i < n; i++) {
    cout << "| ";
    for (int j = 0; j < n; j++) {
      cout << setw(3) << arr[i][j] << " ";
    }
    cout << " |";
    cout << endl;
  }
}

void multiply_naive(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      C_naive[i][j] = 0;
      for (int k = 0; k < n; k++) {
        C_naive[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void mutiply_sum(int i, int j, int n) {
  for (int ii = 0; ii < i + n; ii++) {
    for (int jj = 0; jj < j + n; jj++) {
      C_dnc[ii][jj] += A[ii][jj] + B[ii][jj];
    }
  }
}

void mutiply_dnc(int ci, int cj, int ai, int aj, int bi, int bj, int n) {
  if (n == 1) {
    C_dnc[ci][cj] += A[ai][aj] * B[bi][bj];
    return;
  }

  int n_half = n / 2;

  mutiply_dnc(ci, cj, ai, aj, bi, bj, n_half);
  mutiply_dnc(ci, cj, ai, aj + n_half, bi + n_half, bj, n_half);

  mutiply_dnc(ci, cj + n_half, ai, aj, bi, bj + n_half, n_half);
  mutiply_dnc(ci, cj + n_half, ai, aj + n_half, bi + n_half, bj + n_half,
              n_half);

  mutiply_dnc(ci + n_half, cj, ai + n_half, aj, bi, bj, n_half);
  mutiply_dnc(ci + n_half, cj, ai + n_half, aj + n_half, bi + n_half, bj,
              n_half);

  mutiply_dnc(ci + n_half, cj + n_half, ai + n_half, aj, bi, bj + n_half,
              n_half);
  mutiply_dnc(ci + n_half, cj + n_half, ai + n_half, aj + n_half, bi + n_half,
              bj + n_half, n_half);
}

Matrix<int> multiply_stras(Matrix<int> A, Matrix<int> B) {
  Matrix<int> C(A.getRowSize(), B.getRowSize());
  if (C.getRowSize() == 1) {
    C[0][0] = A[0][0] * B[0][0];
    return C;
  }

  int n_half = A.getRowSize() / 2;
  Matrix<int> A11 = A.split(0, 0, n_half);
  Matrix<int> A12 = A.split(0, n_half, n_half);
  Matrix<int> A21 = A.split(n_half, 0, n_half);
  Matrix<int> A22 = A.split(n_half, n_half, n_half);

  Matrix<int> B11 = B.split(0, 0, n_half);
  Matrix<int> B12 = B.split(0, n_half, n_half);
  Matrix<int> B21 = B.split(n_half, 0, n_half);
  Matrix<int> B22 = B.split(n_half, n_half, n_half);

  Matrix<int> S1 = B12 - B22;
  Matrix<int> S2 = A11 + A12;
  Matrix<int> S3 = A21 + A22;
  Matrix<int> S4 = B21 - B11;
  Matrix<int> S5 = A11 + A22;
  Matrix<int> S6 = B11 + B22;
  Matrix<int> S7 = A12 - A22;
  Matrix<int> S8 = B21 + B22;
  Matrix<int> S9 = A11 - A21;
  Matrix<int> S10 = B11 + B12;

  Matrix<int> p1 = multiply_stras(A11, S1);
  Matrix<int> p2 = multiply_stras(S2, B22);
  Matrix<int> p3 = multiply_stras(S3, B11);
  Matrix<int> p4 = multiply_stras(A22, S4);
  Matrix<int> p5 = multiply_stras(S5, S6);
  Matrix<int> p6 = multiply_stras(S7, S8);
  Matrix<int> p7 = multiply_stras(S9, S10);

  C.partial_fill(0, 0, p4 + p5 + p6 - p2);
  C.partial_fill(0, n_half, p1 + p2);
  C.partial_fill(n_half, 0, p3 + p4);
  C.partial_fill(n_half, n_half, p1 + p5 - p3 - p7);

  return C;
}

int main() {
  fill_rn(A, N);
  fill_rn(B, N);

  Matrix<int> matA(N, N), matB(N, N);
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      matA[r][c] = A[r][c];
      matB[r][c] = B[r][c];
    }
  }

  Matrix<int> matC(N, N);

  multiply_naive(N);
  cout << "Naive way" << endl;
  print_matrix(C_naive, N);
  cout << endl;

  mutiply_dnc(0, 0, 0, 0, 0, 0, N);
  cout << "Naive divide and conquer way" << endl;
  print_matrix(C_dnc, N);
  cout << endl;

  matC = multiply_stras(matA, matB);
  cout << "Strassen way" << endl;
  matC.print();
  cout << endl;

  return 0;
}
