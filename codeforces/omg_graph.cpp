// Omg Graph
// https://codeforces.com/contest/2117/problem/G

#include <bits/stdc++.h>

using namespace std;

int t, n, m;

vector<pair<int, int>> adj_list[200005];
tuple<int, int, int> edges[200005];

vector<int> Dijkstra(int s) {
  vector<int> dist(n + 5, 2e9);

  priority_queue<pair<int, int>> pq;
  dist[s] = 0;
  pq.emplace(0, s);

  while (pq.size()) {
    auto x = pq.top();
    pq.pop();

    int u = x.second;
    int cost = -x.first;

    if (dist[u] < cost) continue;

    for (auto y : adj_list[u]) {
      int v = y.first;
      int next_cost = max(y.second, cost);
      if (next_cost < dist[v]) {
        dist[v] = next_cost;
        pq.emplace(-next_cost, v);
      }
    }
  }

  return dist;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
      adj_list[i].clear();
    }

    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      edges[i] = tie(u, v, w);
      adj_list[u].emplace_back(v, w);
      adj_list[v].emplace_back(u, w);
    }

    auto from_1 = Dijkstra(1);
    auto from_n = Dijkstra(n);

    int ans = 2e9;
    for (int i = 0; i < m; ++i) {    
      int u, v, w;
      tie(u, v, w) = edges[i];

      ans = min(ans, max({from_1[u], from_n[v], w}) + w);
    }

    cout << ans << "\n";
  }

  return 0;
}