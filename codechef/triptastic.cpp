// TripTastic
// https://www.codechef.com/problems/TRPTSTIC

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int t, n, m, k;

bool Solve(const vector<vector<int>>& a, const vector<vector<ll>>& ps, int t) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == 0) continue;

      int x1 = max(1, i - t);
      int y1 = max(1, j - t);
      int x2 = min(n, i + t);
      int y2 = min(m, j + t);

      ll sum =
          ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
      if (sum >= k + 1) return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> n >> m >> k;

    vector<vector<int>> a(n + 5, vector<int>(m + 5, 0));
    vector<vector<ll>> ps(n + 5, vector<ll>(m + 5, 0));

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        cin >> a[i][j];
        ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + a[i][j];
      }
    }

    int lo = 0, hi = 1e6 - 1;
    while (lo <= hi) {
      int m = (lo + hi) / 2;
      if (Solve(a, ps, m)) {
        hi = m - 1;
      } else {
        lo = m + 1;
      }
    }
    cout << (lo == 1e6 ? -1 : lo) << "\n";
  }

  return 0;
}