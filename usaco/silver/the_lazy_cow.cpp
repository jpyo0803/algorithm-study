// The Lazy Cow (Silver)
// https://www.acmicpc.net/problem/10022

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, k;
int arr[805][805];
int ps[805][805];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;

  for (int i = 0; i < 800; ++i) {
    for (int j = 0; j < 800; ++j) {
      arr[i][j] = -1;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      arr[i + j][i - j + n - 1] = x;
    }
  }
  n = 2 * n - 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int a = max(arr[i - 1][j - 1], 0);
      ps[i][j] = a + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (arr[i - 1][j - 1] == -1) continue;
      int x1 = max(0, i - k - 1), y1 = max(0, j - k - 1);
      int x2 = min(n, i + k), y2 = min(n, j + k);

      ans = max(ans, ps[x2][y2] - ps[x1][y2] - ps[x2][y1] + ps[x1][y1]);
    }
  }
  cout << ans << "\n";

  return 0;
}