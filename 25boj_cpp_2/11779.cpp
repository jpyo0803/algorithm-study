// 최소비용 구하기 2
// https://www.acmicpc.net/problem/11779

#include <bits/stdc++.h>

using namespace std;

int n, m, s, t;

vector<pair<int, int>> adj_list[1005];
long long dist[1005];

int p[1005]; // 0 means no parent yet

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    adj_list[u].emplace_back(v, c);
  }

  cin >> s >> t;

  for (int i = 1; i <= n; ++i) dist[i] = 1e15;

  priority_queue<tuple<long long, int, int>> pq; // -cost, u, prev
  pq.emplace(0, s, s);
  dist[s] = 0LL;

  while (pq.empty() == false) {
    auto x = pq.top();
    pq.pop();
    long long cost_so_far = -get<0>(x);
    int u = get<1>(x);
    int prev = get<2>(x);

    if (dist[u] < cost_so_far) continue;

    if (u == t) break;

    for (auto e : adj_list[u]) {
      int v = e.first;
      long long next_cost = cost_so_far + e.second;
      if (next_cost < dist[v]) {
        dist[v] = next_cost;
        p[v] = u;
        pq.emplace(-next_cost, v, u);
      }
    }
  }

  cout << dist[t] << "\n";
  vector<int> paths;
  int curr = t;
  while (p[curr] != curr) {
    paths.push_back(curr);
    curr = p[curr];
  }
  cout << paths.size() << "\n";
  for (int i = paths.size() - 1; i >= 0; --i) {
    cout << paths[i] << " ";
  }
  cout << "\n";

  return 0;
}