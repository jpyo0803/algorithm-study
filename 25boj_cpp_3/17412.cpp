// 도시 왕복하기 1
// https://www.acmicpc.net/problem/17412

#include <bits/stdc++.h>

using namespace std;

int n, p;

vector<int> adj_list[405];
int cap[405][405];
int flow[405][405];
int start_idx[405];
int level[405];

bool Bfs() {
  for (int i = 1; i <= n; ++i) level[i] = -1;

  queue<int> que;
  level[1] = 0;
  que.push(1);

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

  return level[2] != -1;
}

int Solve(int u, int min_flow) {
  if (u == 2) return min_flow;

  for (int& i = start_idx[u]; i < adj_list[u].size(); ++i) {
    int v = adj_list[u][i];
    if (level[v] != level[u] + 1) continue;
    if (cap[u][v] == flow[u][v]) continue;
    int f = Solve(v, min(min_flow, cap[u][v] - flow[u][v]));
    if (f > 0) {
      flow[u][v] += f;
      flow[v][u] -= f;
      return f;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> p;
  while (p--) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
    cap[u][v] = 1;
  }

  int ans = 0;
  while (Bfs()) {
    for (int i = 1; i <= n; ++i) start_idx[i] = 0;
    while (true) {
      int f = Solve(1, 2e9);
      if (f == 0) break;
      ans += f;
    }
  }
  cout << ans << "\n";

  return 0;
}