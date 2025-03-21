// 횡단보도
// https://www.acmicpc.net/problem/24042

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> conn[100010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    conn[u].emplace_back(v, i);
    conn[v].emplace_back(u, i);
  }

  vector<long long> min_dist(n + 10, 1e18);
  min_dist[0] = 0;

  priority_queue<tuple<long long, int, int>> pq;
  for (const auto& y : conn[0]) {
    pq.emplace(-(y.second), y.first, y.second);
  }

  while (pq.size()) {
    auto x = pq.top();
    pq.pop();

    long long dist = -get<0>(x);
    int u = get<1>(x);
    int u_pos = get<2>(x);
    // cout << u << " : " << dist << endl;
    if (dist >= min_dist[u]) continue;
    min_dist[u] = dist;

    for (const auto& y : conn[u]) {
      int v = y.first;
      int v_pos = y.second;
      int delta = v_pos - u_pos;
      if (delta < 0) delta += m;
      long long new_dist = dist + delta;
      pq.emplace(-new_dist, v, v_pos);
    }
  }

  cout << min_dist[n - 1] + 1 << "\n";

  return 0;
}