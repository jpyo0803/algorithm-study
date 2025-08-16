// E - Minimum OR Path (ABC)
// https://atcoder.jp/contests/abc408/tasks/abc408_e

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<tuple<int, int, int>> edges;

class Dsu {
 public:
  Dsu(int n) {
    p_ = vector<int>(n + 1);
    for (int i = 1; i <= n; ++i) p_[i] = i;
  }

  int GetRep(int x) {
    if (p_[x] == x) return x;
    return p_[x] = GetRep(p_[x]);
  }

  void Merge(int x, int y) { p_[y] = x; }

  vector<int> p_;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.emplace_back(u, v, w);
  }

  int ans = (1 << 30) - 1;

  for (int k = 29; k >= 0; --k) {
    Dsu d(n);

    int x = ans ^ (1 << k);
    for (auto [u, v, w] : edges) {
      if ((x | w) != x) continue;
      int ru = d.GetRep(u);
      int rv = d.GetRep(v);
      if (ru != rv) {
        d.Merge(ru, rv);
      }
    }
    if (d.GetRep(1) == d.GetRep(n)) {
      ans = x;
    }
  }

  cout << ans << "\n";

  return 0;
}