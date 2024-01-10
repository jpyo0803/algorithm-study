// 알고리즘 수업 - 깊이 우선 탐색 1
// https://www.acmicpc.net/problem/24479

#include <bits/stdc++.h>

using namespace std;

int ord = 1;
int vis[100010];

set<int> adj[100010];

void Dfs(int x) {
  vis[x] = ord++;
  for (auto e : adj[x]) {
    if (vis[e] == 0) {
      Dfs(e);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M, R;
  cin >> N >> M >> R;

  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }

  Dfs(R);

  for (int i = 1; i <= N; ++i) {
    cout << vis[i] << "\n";
  }

  return 0;
}