// Moo Route II (Silver)
// https://usaco.org/index.php?page=viewproblem2&cpid=1304

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n, m;
  cin >> n >> m;

  vector<vector<tuple<int, int, int>>> adj(n);
  for (int i = 0; i < m; ++i) {
    int c, r, d, s;
    cin >> c >> r >> d >> s;
    c--, d--;
    adj[c].emplace_back(d, r, s);
  }

  for (int i = 0; i < n; ++i) {
    sort(adj[i].begin(), adj[i].end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
      return get<1>(a) > get<1>(b);
    });
  }
  vector<int> iv(n, 0);

  vector<int> av(n);
  for (auto& e : av) cin >> e;

  vector<int> mt(n, -1);
  queue<pair<int, int>> que;
  que.emplace(0, 0);
  mt[0] = 0;
  
  while (que.size()) {
    auto e = que.front();
    que.pop();
    int from = e.first, t = e.second;

    for (int& idx = iv[from]; idx < adj[from].size(); idx++) {
      auto f = adj[from][idx];
      int depart = get<1>(f);
      if (depart < t) break;

      int to = get<0>(f);
      int arrive = get<2>(f);
      if (mt[to] != -1 && mt[to] <= arrive) continue;
      mt[to] = arrive;
      que.emplace(to, arrive + av[to]);
    }
  }

  for (auto e : mt) cout << e << "\n";

  return 0;
}