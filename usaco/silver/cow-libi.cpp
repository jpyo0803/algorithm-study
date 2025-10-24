// Cow-libi (Silver)
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int g, n;

int UpperBound(const vector<tuple<int, int, int>>& v, int x) {
  int l = 0, r = v.size();
  while (l < r) {
    int m = (l + r) / 2;
    if (get<0>(v[m]) <= x) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return l;
}

ll DistSqr(int x1, int y1, int x2, int y2) {
  ll dx = x1 - x2;
  ll dy = y1 - y2;
  return dx * dx + dy * dy;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> g >> n;
  vector<tuple<int, int, int>> gv;
  for (int i = 0; i < g; ++i) {
    int x, y, t;
    cin >> x >> y >> t;
    gv.emplace_back(t, x, y);
  }
  sort(gv.begin(), gv.end());

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x, y, t;
    cin >> x >> y >> t;
    int p = UpperBound(gv, t);
    bool ok = true;  // if true, not innocent
    if (p > 0) {     // check left
      int t2, x2, y2;
      tie(t2, x2, y2) = gv[p - 1];
      ll dt = t - t2;
      ll distsqr = DistSqr(x, y, x2, y2);
      if (distsqr > dt * dt) ok = false;
    }
    if (p < g) {
      int t2, x2, y2;
      tie(t2, x2, y2) = gv[p];
      ll dt = t - t2;
      ll distsqr = DistSqr(x, y, x2, y2);
      if (distsqr > dt * dt) ok = false;
    }
    if (!ok) ans++;
  }
  cout << ans << "\n";

  return 0;
}