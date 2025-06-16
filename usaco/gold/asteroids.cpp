// Asteroids (Gold)
// https://www.acmicpc.net/problem/1867

#include <bits/stdc++.h>

using namespace std;

int n, k;

int level[1005];
vector<int> adj_list[1005];
int cap[1005][1005];
int flow[1005][1005];
int start_idx[1005];
int s;
int t;

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

int Solve(int u, int min_flow) {
  if (u == t) return min_flow;

  for (int& i = start_idx[u]; i < adj_list[u].size(); ++i) {
    int v = adj_list[u][i];
    if (level[u] + 1 == level[v] && cap[u][v] > flow[u][v]) {
      int f = Solve(v, min(min_flow, cap[u][v] - flow[u][v]));
      if (f > 0) {
        flow[u][v] += f;
        flow[v][u] -= f;
        return f;
      }
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  s = 0;
  t = 2 * n + 1;
  while (k--) {
    int x, y;
    cin >> x >> y;
    y += n;
    adj_list[x].push_back(y);
    adj_list[y].push_back(x);
    cap[x][y] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    adj_list[0].push_back(i);
    cap[0][i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    adj_list[i + n].push_back(t);
    cap[i + n][t] = 1;
  }

  int ans = 0;
  while (Bfs()) {
    for (int i = 0; i <= t; ++i) start_idx[i] = 0;

    while (true) {
      int f = Solve(s, 2e9);
      if (f == 0) break;
      ans += f;
    }
  }

  cout << ans << "\n";

  return 0;
}