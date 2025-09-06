// 체스판 다시 칠하기 
// https://www.acmicpc.net/problem/1018

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m;
bool arr[55][55];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char x;
      cin >> x;
      arr[i][j] = x == 'B';
    }
  }

  int ans = 1e9;
  for (int i = 0; i <= n - 8; ++i) {
    for (int j = 0; j <= m - 8; ++j) {
      int c1 = 0, c2 = 0; // b, w
      for (int i2 = 0; i2 < 8; ++i2) {
        bool b1 = (i2 % 2) == 0;
        bool b2 = (i2 % 2);
        for (int j2 = 0; j2 < 8; ++j2) {
          if (arr[i + i2][j + j2] != b1) c1++;
          if (arr[i + i2][j + j2] != b2) c2++;

          b1 = !b1;
          b2 = !b2;
        }
      }
      ans = min({ans, c1, c2});
    }
  }
  cout << ans << "\n";

  return 0;
}