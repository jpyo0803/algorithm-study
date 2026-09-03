// Rank
// https://dmoj.ca/problem/acsl1p4

#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<int> adj[22];
bool vis[22];

bool Dfs(int x, int s) {
  if (vis[x]) {
    return x == s;
  }
  vis[x] = true;
  bool ret = false;
  for (auto y : adj[x]) {
    ret |= Dfs(y, s);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;
  
  for (int i = 0; i < k; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--;
    if (c > d) {
      adj[a].push_back(b);
    } else {
      adj[b].push_back(a);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) vis[j] = false; 
    if (Dfs(i, i)) ans++;
  }
  cout << ans << "\n";

  return 0;
}