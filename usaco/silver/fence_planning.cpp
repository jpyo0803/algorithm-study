// Fence Planning (Silver)
// https://usaco.org/index.php?page=viewproblem2&cpid=944

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);
  
  ifstream cin("fenceplan.in");
  ofstream cout("fenceplan.out");

  int n, m;
  cin >> n >> m;
  
  vector<pair<int, int>> cv(n);
  for (auto& e : cv) cin >> e.first >> e.second;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<bool> vis(n, false);

  int ans = 1e9;
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    vis[i] = true;
    queue<int> q;
    q.push(i);
    vector<int> g;
    while (q.size()) {
      auto curr = q.front();
      q.pop();
      g.push_back(curr);
      for (auto next : adj[curr]) {
        if (vis[next]) continue;
        q.push(next);
        vis[next] = true;
      }
    }
    int x1 = 1e8, x2 = 0, y1 = 1e8, y2 = 0;
    for (auto e : g) {
      x1 = min(x1, cv[e].first);
      x2 = max(x2, cv[e].first);
      y1 = min(y1, cv[e].second);
      y2 = max(y2, cv[e].second);
    }
    int dx = x2 - x1;
    int dy = y2 - y1;
    ans = min(ans, 2 * (dx + dy));
  }
  cout << ans << "\n";

  return 0;
}