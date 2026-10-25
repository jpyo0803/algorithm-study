// Redistributing Gifts (Silver)
// https://usaco.org/index.php?page=viewproblem2&cpid=1206

#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool vis[501];
vector<int> adj[501];

bool CanReach(int x, int r) {
  if (x == r) return true;

  bool ret = false;
  for (auto y : adj[x]) {
    if (vis[y]) continue;
    vis[y] = true;
    ret |= CanReach(y, r);
  }
  return ret;
}  

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    bool seen = false;
    for (int j = 1; j <= n; ++j) {
      int x;
      cin >> x;
      if (seen) continue;
      if (x == i) seen = true;
      adj[i].push_back(x);
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (auto g : adj[i]) {
      for (int j = 1; j <= n; ++j) vis[j] = false;
      if (CanReach(g, i)) {
        cout << g << "\n";
        break;
      }
    }
  }

  return 0;
}