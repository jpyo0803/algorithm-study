// Wormhole Sort (Silver)
// https://usaco.org/index.php?page=viewproblem2&cpid=992

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);
  
  ifstream cin("wormsort.in");
  ofstream cout("wormsort.out");

  int n, m;
  cin >> n >> m;
  vector<int> nv(n);
  for (auto& e : nv) {
    cin >> e;
    e--;
  }

  vector<vector<int>> mv(m);
  for (int i = 0; i < m; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    a--, b--;
    mv[i].push_back(a);
    mv[i].push_back(b);
    mv[i].push_back(w);
  }

  vector<int> ov;
  for (int i = 0; i < n; ++i) {
    if (nv[i] != i) {
      ov.push_back(i);
    }
  }
  if (ov.empty()) {
    cout << "-1\n";
    return 0;
  }

  int lo = 1, hi = 1e9;
  int ans;

  while (lo <= hi) {
    int w = lo + (hi - lo) / 2;
    vector<vector<int>> adj(n);
    for (auto& e : mv) {
      int a = e[0], b = e[1], c = e[2];
      if (c < w) continue;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    vector<bool> vis(n, false);
    vector<set<int>> gv;
    for (int i = 0; i < n; ++i) {
      if (vis[i]) continue;
      set<int> grp;
      queue<int> que;
      que.push(i);
      vis[i] = true;
      while (que.size()) {
        auto e = que.front();
        que.pop();
        grp.insert(e);

        for (auto f : adj[e]) {
          if (vis[f]) continue;
          que.push(f);
          vis[f] = true;
        }
      }
      gv.push_back(grp);
    }

    bool ok = true;
    for (auto a : ov) {
      int b = nv[a];
      bool good = false;
      for (auto& g : gv) {
        bool hasa = g.find(a) != g.end();
        bool hasb = g.find(b) != g.end();
        if (hasa && hasb) good = true;
      }
      if (good == false) {
        ok = false;
        break;
      }
    }

    if (ok) {
      ans = w;
      lo = w + 1;
    } else {
      hi = w - 1;
    }
  }
  cout << ans << "\n";

  return 0;
}