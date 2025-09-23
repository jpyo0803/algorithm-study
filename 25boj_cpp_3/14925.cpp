// 목장 건설하기
// https://www.acmicpc.net/problem/14925

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int m, n;
int arr[1005][1005];
int ps[1005][1005];

bool IsEmpty(int x1, int y1, int x2, int y2) {
  int a = ps[x1 - 1][y1 - 1];
  int b = ps[x2][y1 - 1];
  int c = ps[x1 - 1][y2];
  int d = ps[x2][y2];
  return (d - b - c + a == 0);
}

bool Solve(int L) {
  bool ok = false;
  for (int i = 1; i <= m - L + 1 && !ok; ++i) {
    for (int j = 1; j <= n - L + 1 && !ok; ++j) {
      if (IsEmpty(i, j, i + L - 1, j + L - 1)) {
        ok = true;
      }
    }
  }
  return ok;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      ps[i + 1][j + 1] = ps[i + 1][j] + arr[i][j];
    }
    for (int j = 0; j < n; ++j) {
      ps[i + 1][j + 1] += ps[i][j + 1];
    }
  }

  int l = 0, r = min(m, n);
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (Solve(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << ans << "\n";

  return 0;
}