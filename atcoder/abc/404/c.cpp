// C - Cycle Graph? (ABC)
// https://atcoder.jp/contests/abc404/tasks/abc404_c

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m, a, b;

vector<int> adj[200005];

bool vis[200005];

int Solve(int u) {
  int ret = 1;
  for (auto v : adj[u]) {
    if (vis[v]) continue;
    vis[v] = true;
    ret += Solve(v);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  bool ok = true;
  if (n != m) ok = false;
  for (int i = 0; i < n && ok; ++i) {
    if (adj[i].size() != 2) ok = false;
  }

  vis[0] = true;
  int ret = Solve(0);
  if (ret != n) ok = false;

  cout << (ok ? "Yes" : "No") << "\n";

  return 0;
}