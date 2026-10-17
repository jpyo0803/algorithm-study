// Connecting Two Barns (Silver)
// https://usaco.org/index.php?page=viewproblem2&cpid=1159

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    vector<vector<int>> gv;
    vector<bool> vis(n);

    int last_idx;
    for (int i = 0; i < n; ++i) {
      if (vis[i]) continue;
      queue<int> q;
      q.push(i);
      vis[i] = true;

      vector<int> g;
      while (q.size()) {
        auto e = q.front();
        if (e == n - 1) {
          last_idx = gv.size();
        }
        q.pop();
        g.push_back(e);
        for (auto f : adj[e]) {
          if (vis[f]) continue;
          vis[f] = true;
          q.push(f);
        }
      }
      gv.push_back(g);
    }

    bool done = false;
    for (auto e : gv[0]) {
      if (e == n - 1) {
        cout << "0\n";
        done = true;
        break;
      }
    }
    if (done) continue;

    for (auto& g : gv) {
      sort(g.begin(), g.end());
    }

    ll ans = 1e15;
    for (auto u : gv[0]) {
      auto it = lower_bound(gv[last_idx].begin(), gv[last_idx].end(), u);
      if (it != gv[last_idx].end()) {
        ll d = u - *it;
        ans = min(ans, d * d);
      }
      if (it != gv[last_idx].begin()) {
        it--;
        ll d = u - *it;
        ans = min(ans, d * d);
      }
    }

    for (int i = 1; i < gv.size(); ++i) {
      if (i == last_idx) continue;
      ll min_a = 1e15, min_b = 1e15;
      for (auto via : gv[i]) {
        auto it_a = lower_bound(gv[0].begin(), gv[0].end(), via);
        if (it_a != gv[0].end()) {
          ll d = via - *it_a;
          min_a = min(min_a, d * d);
        }
        if (it_a != gv[0].begin()) {
          it_a--;
          ll d = via - *it_a;
          min_a = min(min_a, d * d);
        }
        auto it_b = lower_bound(gv[last_idx].begin(), gv[last_idx].end(), via);
        if (it_b != gv[last_idx].end()) {
          ll d = via - *it_b;
          min_b = min(min_b, d * d);
        }
        if (it_b != gv[last_idx].begin()) {
          it_b--;
          ll d = via - *it_b;
          min_b = min(min_b, d * d);
        }
      }
      ans = min(ans, min_a + min_b);
    }

    cout << ans << "\n";
  }

  return 0;
}