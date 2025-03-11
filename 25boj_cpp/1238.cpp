// 파티
// https://www.acmicpc.net/problem/1238

#include <bits/stdc++.h>

using namespace std;

int n, m, x;

vector<pair<int, int>> adj_list[1005];
vector<pair<int, int>> inv_adj_list[1005];

vector<int> Solve(bool inv) {
  const auto& adj_lst = inv ? inv_adj_list : adj_list;

  vector<int> dist(n + 1, 1e9);  // account virtual terminal node t == n

  int t = n;

  priority_queue<pair<int, int>> pq;  // cost, node
  pq.emplace(0, x);                   // start node is always 'x'

  while (pq.empty() == false) {
    auto x = pq.top();
    pq.pop();

    int curr_dist = -x.first;
    int u = x.second;

    if (curr_dist >= dist[u]) continue;
    dist[u] = curr_dist;

    for (auto y : adj_lst[u]) {
      int v = y.first;
      int cost = y.second;

      int new_dist = curr_dist + cost;
      if (new_dist < dist[v]) {
        pq.emplace(-new_dist, v);
      }
    }
  }

  return dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> x;
  x--;  // 0-ind

  // unidirectional implies that cost of go and come back might be different
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    u--;
    v--;  // 0-ind

    adj_list[u].emplace_back(v, c);
    inv_adj_list[v].emplace_back(u, c);
    // Only one path from u to v exist
  }
  // set 'n' as virtual node
  for (int i = 0; i < n; ++i) {
    adj_list[i].emplace_back(n, 0);
    inv_adj_list[i].emplace_back(n, 0);
  }

  // set starting pos to 'x'

  auto res1 = Solve(false);
  auto res2 = Solve(true);

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i == x) continue;
    ans = max(ans, res1[i] + res2[i]);
  }

  cout << ans << "\n";

  return 0;
}