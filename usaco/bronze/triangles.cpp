// Triangles (Bronze)
// https://www.acmicpc.net/problem/18786

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<pair<int, int>> pts(n);
  for (int i = 0; i < n; ++i) cin >> pts[i].first >> pts[i].second;

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x1 = pts[i].first, y1 = pts[i].second;
    for (int j = 0; j < n; ++j) {
      int x2 = pts[j].first, y2 = pts[j].second;
      if (y1 != y2) continue;
      for (int k = 0; k < n; ++k) {
        int x3 = pts[k].first, y3 = pts[k].second;
        if (x2 != x3) continue;
        int area = abs(x1 - x2) * abs(y2 - y3);
        ans = max(ans, area);
      }
    }
  }

  cout << ans << "\n";

  return 0;
}