// D. Rudolph and Christmas Tree
// https://codeforces.com/contest/1846/problem/D

#include <bits/stdc++.h>

using namespace std;

int t, n, d, h;

double Area(int y1, int y2) {
  double dy = y2 - y1 > h ? h : y2 - y1;
  double x = dy * d / (2 * h);
  double top = d - 2 * x;
  return (top + d) * dy;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> n >> d >> h;
    vector<int> yv(n);
    for (int i = 0; i < n; ++i) cin >> yv[i];
    sort(yv.begin(), yv.end());

    double ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += Area(yv[i], i + 1 < n ? yv[i + 1] : 2e9 + 10);
    }
    cout << fixed << setprecision(6) << ans / 2 << "\n";
  }

  return 0;
}