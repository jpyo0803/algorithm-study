// 해킹
// https://www.acmicpc.net/problem/10282

#include <bits/stdc++.h>

using namespace std;

int t, n, d, c, a, b, s;

int dist[10005];
vector<pair<int, int>> adj_list[10005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> n >> d >> c;

    for (int i = 1; i <= n; ++i) {
      dist[i] = 1e9;
      adj_list[i].clear();
    }

    for (int i = 0; i < d; ++i) {
      cin >> a >> b >> s;  // b can infect a
      adj_list[b].emplace_back(a, s);
    }

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, c);
    dist[c] = 0;

    int ans_cnt = 0;
    int ans_time = 0;

    while (pq.empty() == false) {
      auto x = pq.top();
      pq.pop();
      int cost = -x.first;
      int u = x.second;

      if (dist[u] < cost) continue;
      ans_cnt++;
      ans_time = max(ans_time, dist[u]);

      for (auto e : adj_list[u]) {
        int v = e.first;
        int next_cost = cost + e.second;
        if (dist[v] > next_cost) {
          dist[v] = next_cost;
          pq.emplace(-next_cost, v);
        }
      }
    }

    cout << ans_cnt << " " << ans_time << "\n";
  }

  return 0;
}