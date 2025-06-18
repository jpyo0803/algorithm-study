// 열혈강호 4
// https://www.acmicpc.net/problem/11378

#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int cap[2005][2005];
int flow[2005][2005];
int start_idx[2005];
int level[2005];
int s, t;
vector<int> adj_list[2005];

bool Bfs() {
  for (int i = 0; i <= t; ++i) level[i] = -1;

  queue<int> que;
  level[s] = 0;
  que.push(s);

  while (que.size()) {
    int u = que.front();
    que.pop();

    for (auto v : adj_list[u]) {
      if (level[v] != -1) continue;
      if (cap[u][v] == flow[u][v]) continue;
      level[v] = level[u] + 1;
      que.push(v);
    }
  }

  return level[t] != -1;
}

int Dfs(int u, int mf) {
  if (u == t) return mf;

  for (int& i = start_idx[u]; i < adj_list[u].size(); ++i) {
    int v = adj_list[u][i];
    if (level[v] != level[u] + 1) continue;
    if (cap[u][v] == flow[u][v]) continue;
    int f = Dfs(v, min(mf, cap[u][v] - flow[u][v]));
    if (f > 0) {
      flow[u][v] += f;
      flow[v][u] -= f;
      return f;
    }
  }

  return 0;
}

int Solve(int max_cap) {
  for (int i = 0; i <= t; ++i) {
    for (int j = 0; j <= t; ++j) {
      flow[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; ++i) cap[s][i] = max_cap;

  int ret = 0;

  while (Bfs()) {
    for (int i = 0; i <= t; ++i) start_idx[i] = 0;
    while (true) {
      int f = Dfs(s, 2e9);
      if (f == 0) break;
      ret += f;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  s = 0, t = n + m + 1;

  for (int u = 1; u <= n; ++u) {
    int x;
    cin >> x;
    while (x--) {
      int v;
      cin >> v;
      v += n;
      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
      cap[u][v] = 1;
    }
  }

  for (int v = 1; v <= n; ++v) adj_list[s].push_back(v);
  for (int u = 1; u <= m; ++u) {
    adj_list[u + n].push_back(t);
    cap[u + n][t] = 1;
  }

  int ans1 = Solve(1);
  int ans2 = Solve(1e6);

  cout << min(ans1 + k, ans2) << "\n";

  return 0;
}