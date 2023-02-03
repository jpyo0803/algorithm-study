// Triangles
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1011

#include <bits/stdc++.h>

using namespace std;

int GetTriangelArea(const vector<pair<int, int>>& pts, int i, int j, int k) {
  if (pts[i].second == pts[j].second && pts[i].first == pts[k].first) {
    return abs((pts[i].first - pts[j].first) * (pts[i].second - pts[k].second));
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<pair<int, int>> pts(N);
  for (int i = 0; i < N; ++i) {
    cin >> pts[i].first >> pts[i].second;
  }

  int ans = 0;                   // 2e4 * 2e4 / 2 = 2e8 is max possible
  for (int i = 0; i < N; ++i) {  // set 'i' as pivot
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {  // O(N^3) = 100^3
        // pivot at bottom right
        ans = max(ans, GetTriangelArea(pts, i, j, k));
      }
    }
  }

  cout << ans << "\n";

  return 0;
}