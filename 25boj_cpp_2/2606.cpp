// 바이러스
// https://www.acmicpc.net/problem/2606

#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> adj_list[105];

bool visited[105];

int Dfs(int u) {
  int ret = 1;
  for (auto v : adj_list[u]) {
    if (visited[v]) continue;
    visited[v] = true;
    ret += Dfs(v);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj_list[x].push_back(y);
    adj_list[y].push_back(x);
  }

  visited[1] = true;
  int ans = Dfs(1);
  cout << ans - 1 << "\n";

  return 0;
}