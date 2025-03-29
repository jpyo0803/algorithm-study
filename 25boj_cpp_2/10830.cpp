// 행렬 제곱
// https://www.acmicpc.net/problem/10830

/*
  Repeated Square
  matrix require matmul and squaring itself
*/

#include <bits/stdc++.h>

using namespace std;

int n;
long long b;

int arr[5][5];
int ans[5][5];
int buf[5][5];

void Matmul(int a[5][5], int b[5][5]) {
  // accumlates to a
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int sum = 0;
      for (int k = 0; k < n; ++k) {
        sum += a[i][k] * b[k][j];
        sum %= 1000;
      }
      buf[i][j] = sum;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = buf[i][j];
    }
  }
}

void RepSqr(long long exp) {
  if (exp == 0LL) return;  // just return identity matrix

  RepSqr(exp / 2LL);
  Matmul(ans, ans);
  if (exp & 1 == 1) {
    Matmul(ans, arr);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> b;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
      if (i == j) ans[i][j] = 1;  // identity mat
    }
  }

  RepSqr(b);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}