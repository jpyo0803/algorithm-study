// 택배 배송
// https://www.acmicpc.net/problem/5972

#include <bits/stdc++.h>

using namespace std;

int n, m;

map<int, int> adj_list[50010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    
    auto it = adj_list[u].find(v);
    if (it == adj_list[u].end()) {
      adj_list[u][v] = 1e9;
      adj_list[v][u] = 1e9;
    }

    adj_list[u][v] = min(adj_list[u][v], c);
    adj_list[v][u] = min(adj_list[v][u], c);
  }

  vector<int> min_cost(50010, 1e9);

  priority_queue<pair<int, int>> pq; // cost so far, vertex
  pq.emplace(0, 1); // 1 -> N

  while (pq.empty() == false) {
    auto x = pq.top();
    pq.pop();

    int cost = -x.first;
    int u = x.second;
    if (min_cost[u] <= cost) continue;
    min_cost[u] = cost;

    for (const auto& [v, c] : adj_list[u]) {
      int new_cost = cost + c;
      if (new_cost < min_cost[v]) {
        pq.emplace(-new_cost, v);
      }
    }
  }

  cout << min_cost[n] << "\n";

  return 0;
}