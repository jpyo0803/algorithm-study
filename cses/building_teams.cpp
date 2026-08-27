// Building Teams
// https://cses.fi/problemset/task/1668

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m;
vector<int> adj[100005];
int vis[100005]; // 0 means not visited, 1 or 2 means team is assigned

bool Dfs(int x, int color) {
  vis[x] = color;
  int next_color = 3 - color;

  bool ret = true; 
  for (auto y : adj[x]) {
    if (vis[y] == 0) {
      ret &= Dfs(y, next_color);
    } else if (vis[y] == color) {
      return false;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  bool res = true;
  for (int i = 1; i <= n; ++i) {
    if (vis[i] != 0) continue;
    res &= Dfs(i, 1);
  }

  if (res == false) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  for (int i = 1; i <= n; ++i) {
    cout << vis[i] << " ";
  } 
  cout << "\n";

  return 0;
}