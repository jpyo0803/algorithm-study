// Flight Routes Check
// https://cses.fi/problemset/task/1682

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m;
vector<vector<int>> adj, badj;
vector<bool> can, bcan;

void Dfs(int x, const vector<vector<int>>& adj, vector<bool>& can) {
  if (can[x]) return;
  can[x] = true;
  for (auto y : adj[x]) {
    Dfs(y, adj, can);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  adj.resize(n + 5);
  badj.resize(n + 5);
  can.resize(n + 5);
  bcan.resize(n + 5);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    badj[b].push_back(a);
  }

  Dfs(1, adj, can);
  Dfs(1, badj, bcan);
  int cnt = 0, cnt2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (can[i]) cnt++;
    if (bcan[i]) cnt2++;
  }
  if (cnt == n && cnt2 == n) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
    for (int i = 2; i <= n; ++i) {
      if (can[i] == false) {
        cout << 1 << " " << i << "\n";
        break;
      }
      if (bcan[i] == false) {
        cout << i << " " << 1 << "\n";
        break;
      }
    }
  }

  return 0;
}