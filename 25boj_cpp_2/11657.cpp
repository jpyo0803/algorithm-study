// 타임머신
// https://www.acmicpc.net/problem/11657

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<tuple<int, int, int>> edges;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    // unidir
    edges.emplace_back(a, b, c);
  }

  vector<long long> dist(n + 10, 1e17);
  dist[1] = 0;

  bool cycle_detected = false;
  for (int i = 0; i < n; ++i) {
    for (auto e : edges) {
      int u = get<0>(e);
      int v = get<1>(e);
      int cost = get<2>(e);

      if (dist[v] > dist[u] + cost) {
        dist[v] = dist[u] + cost;
        if (i == n - 1 && dist[v] < 5e16) {
          cycle_detected = true;
        }
      }
    }
  }

  if (cycle_detected) {
    cout << "-1\n";
  } else {
    for (int i = 2; i <= n; ++i) {
      cout << (dist[i] > 5e16 ? -1 : dist[i]) << "\n";
    }
  }

  return 0;
}