// F - Contraction (ABC)
// https://atcoder.jp/contests/abc411/tasks/abc411_f

#include <bits/stdc++.h>

using namespace std;

int n, m, q;
int parent[300005];
set<int> adj_list[300005];
pair<int, int> edges[300005];

int UF(int x) {
  if (parent[x] == 0) return x;
  return parent[x] = UF(parent[x]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[i].first = u, edges[i].second = v;
    adj_list[u].insert(v);
    adj_list[v].insert(u);
  }

  int ans = m;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;

    int a, b;
    tie(a, b) = edges[x];
    int ra = UF(a), rb = UF(b);
    if (ra != rb) {
      if (adj_list[ra].size() < adj_list[rb].size()) swap(ra, rb);
      ans -= adj_list[ra].size() + adj_list[rb].size() - 1;

      adj_list[ra].erase(rb);
      adj_list[rb].erase(ra);

      parent[rb] = ra;
      for (auto e : adj_list[rb]) {
        adj_list[e].erase(rb);
        adj_list[e].insert(ra);
      }

      for (auto e : adj_list[rb]) {
        adj_list[ra].insert(e);
      }
      adj_list[rb].clear();

      ans += adj_list[ra].size();
    }
    cout << ans << "\n";
  }

  return 0;
}