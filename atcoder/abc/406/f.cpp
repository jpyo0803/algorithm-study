// F - Compare Tree Weights (ABC)
// https://atcoder.jp/contests/abc406/tasks/abc406_f

#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<int> adj[300005];
int f[300005];
int lidx[300005];
int ridx[300005];

vector<pair<int, int>> edges;

int trees[600005];
void Update(int x, int v) {
  x += n;
  trees[x] += v;
  for (x /= 2; x >= 1; x /= 2) {
    trees[x] = trees[x * 2] + trees[x * 2 + 1]; 
  }
}

int Query(int l, int r) {
  int s = 0;
  l += n, r += n;
  while (l <= r) {
    if (l % 2 == 1) s += trees[l++];
    if (r % 2 == 0) s += trees[r--];
    l /= 2, r /= 2;
  }
  return s;
}

int ord = 0;
void Dfs(int u, int prev) {
  f[u] = lidx[u] = ord;
  ord++;
  for (auto v : adj[u]) {
    if (v == prev) continue;
    Dfs(v, u);
  }
  ridx[u] = ord;
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) Update(i, 1);

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edges.emplace_back(u, v);
  }

  Dfs(1, -1);

  cin >> q;
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int x, w;
      cin >> x >> w;
      Update(f[x - 1], w);
    } else {
      int y;
      cin >> y;
      y--;
      int u, v;
      tie(u, v) = edges[y];
      int x = f[u] > f[v] ? u : v;
      cout << abs(Query(0, n - 1) - 2 * Query(lidx[x], ridx[x] - 1)) << "\n";
    }
  }

  return 0;
}