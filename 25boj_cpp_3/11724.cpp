// 연결 요소의 개수
// https://www.acmicpc.net/problem/11724

#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<int> adj[1005];
bool vis[1005];
int n, m;

void Dfs(int u) {
  for (auto v : adj[u]) {
    if (vis[v]) continue;
    vis[v] = true;
    Dfs(v);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    vis[i] = true;
    ans++;
    Dfs(i);
  }

  cout << ans << "\n";

  return 0;
}