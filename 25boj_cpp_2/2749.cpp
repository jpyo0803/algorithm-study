// 피보나치 수 3
// https://www.acmicpc.net/problem/2749

/*
  [1 1; 1 0]^n = [Fn+1 Fn; Fn Fn-1]
*/

#include <bits/stdc++.h>

using namespace std;

long long n;

long long arr[2][2];
long long ans[2][2];
long long buf[2][2];

void Matmul(long long x[2][2], long long y[2][2]) {
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      long long sum = 0;
      for (int k = 0; k < 2; ++k) {
        sum += x[i][k] * y[k][j];
        sum %= 1000000LL;
      }
      buf[i][j] = sum;
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      x[i][j] = buf[i][j];
    }
  }
}

void ReqSqr(long long exp) {
  if (exp == 0LL) {
    ans[0][0] = ans[1][1] = 1LL;
    return;
  }

  ReqSqr(exp >> 1LL);
  Matmul(ans, ans);
  if (exp & 1 == 1LL) {
    Matmul(ans, arr);
  }

  // cout << exp << endl;
  // for (int i = 0; i < 2; ++i) {
  //   for (int j = 0; j < 2; ++j) {
  //     cout << ans[i][j] << " ";
  //   }
  //   cout << endl;
  // }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  arr[0][0] = arr[0][1] = arr[1][0] = 1LL;

  ReqSqr(n);

  cout << ans[0][1] << "\n";

  return 0;
}