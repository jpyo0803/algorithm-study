// Birthday Party
// https://open.kattis.com/problems/birthday

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while (true) {
    int p, c;
    cin >> p >> c;
    if (p == 0 && c == 0) break;

    vector<vector<int>> adj(p);
    vector<pair<int, int>> edges;
    for (int i = 0; i < c; ++i) {
      int a, b;
      cin >> a >> b;
      edges.emplace_back(a, b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    
    bool ans = false;
    for (int i = 0; i < c; ++i) {
      vector<bool> vis(p, false);
      queue<int> q;
      q.push(0);
      vis[0] = true;
      int cnt = 1;

      while (q.size()) {
        auto e = q.front();
        q.pop();

        for (auto f : adj[e]) {
          if ((edges[i].first == e && edges[i].second == f) || (edges[i].first == f && edges[i].second == e)) continue;
          if (vis[f]) continue;
          vis[f] = true;
          cnt++;
          q.push(f);
        }
      }
      if (cnt < p) {
        ans = true;
        break;
      }
    }
    cout << (ans ? "Yes" : "No") << "\n"; 
  }

  return 0;
}