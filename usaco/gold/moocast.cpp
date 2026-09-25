// Moocast (Gold)
// https://usaco.org/index.php?page=viewproblem2&cpid=669

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int Dist(pair<int, int> a, pair<int, int> b) {
  int dx = a.first - b.first;
  int dy = a.second - b.second;
  return dx * dx + dy * dy;
}

bool CanReach(pair<int, int> a, pair<int, int> b, int r) {
  int d = Dist(a, b);
  return d <= r;
} 

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);
  
  ifstream cin("moocast.in");
  ofstream cout("moocast.out");

  int n;
  cin >> n;
  vector<pair<int, int>> cv(n);
  for (auto& e : cv) cin >> e.first >> e.second;

  int lo = 1, hi = 1250000000;
  int ans;
  while (lo <= hi) {
    int r = lo + (hi - lo) / 2;

    vector<bool> vis(n, false);
    queue<int> que;
    que.push(0);
    vis[0] = true;
    while (que.size()) {
      auto u = que.front();
      que.pop();

      for (int v = 0; v < n; ++v) {
        if (vis[v]) continue;
        if (CanReach(cv[u], cv[v], r) == false) continue;
        vis[v] = true;
        que.push(v);
      }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (vis[i] == false) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans = r;
      hi = r - 1;
    } else {
      lo = r + 1;
    }
  }
  cout << ans << "\n";

  return 0;
}