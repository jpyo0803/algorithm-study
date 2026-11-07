// Subarray Sum Constraints
// https://cses.fi/problemset/task/3294

#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll ps[5005];
bool vis[5005];
vector<vector<int>> adj[5005];

bool Dfs(int x) {
  bool ret = true;
  for (auto e : adj[x]) {
    int y = e[0], s = e[1];
    if (vis[y]) {
      if (ps[y] != ps[x] + s) return false;
      continue;
    }
    vis[y] = true;
    ps[y] = ps[x] + s;
    ret &= Dfs(y);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int l, r, s;
    cin >> l >> r >> s;
    l--;
    adj[l].push_back({r, s});
    adj[r].push_back({l, -s});
  }

  bool ok = true;
  for (int i = 0; i <= n; ++i) {
    if (vis[i]) continue;
    ps[i] = 0;
    vis[i] = true;
    bool res = Dfs(i);
    if (res == false) {
      ok = false;
      break;
    }
  }
  
  if (ok) {
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
      cout << ps[i] - ps[i - 1] << " ";
    }
    cout << "\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}