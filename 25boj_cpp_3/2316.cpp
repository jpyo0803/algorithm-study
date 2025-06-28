// 도시 왕복하기 2
// https://www.acmicpc.net/problem/2316

#include <bits/stdc++.h>

using namespace std;

int n, p;
int cap[805][805];
int flow[805][805];
int level[805];
vector<int> adj_list[805];
int start_idx[805];

int s = 1, t = 2;

bool Bfs() {
  for (int i = 1; i <= 2 * n; ++i) level[i] = -1;

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

int Dfs(int u, int min_flow) {
  if (u == t) return min_flow;

  for (int& i = start_idx[u]; i < adj_list[u].size(); ++i) {
    int v = adj_list[u][i];
    if (level[v] != level[u] + 1) continue;
    if (cap[u][v] == flow[u][v]) continue;
    int f = Dfs(v, min(min_flow, cap[u][v] - flow[u][v]));
    if (f > 0) {
      flow[u][v] += f;
      flow[v][u] -= f;
      return f;
    }
  }

  return 0;
}

void Connect(int x, int y) {
  if (cap[x][x + n] == 0) {
    cap[x][x + n] = 1;
    adj_list[x].push_back(x + n);
    adj_list[x + n].push_back(x);
  }
  if (cap[y][y + n] == 0) {
    cap[y][y + n] = 1;
    adj_list[y].push_back(y + n);
    adj_list[y + n].push_back(y);
  }
  if (cap[x + n][y] == 0) {
    cap[x + n][y] = 1;
    adj_list[x + n].push_back(y);
    adj_list[y].push_back(x + n);
  }
  if (cap[y + n][x] == 0) {
    cap[y + n][x] = 1;
    adj_list[y + n].push_back(x);
    adj_list[x].push_back(y + n);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> p;
  for (int i = 0; i < p; ++i) {
    int x, y;
    cin >> x >> y;
    Connect(x, y);
  }
  cap[1][1 + n] = 1e9;
  cap[2][2 + n] = 1e9;

  int ans = 0;
  while (Bfs()) {
    for (int i = 1; i <= 2 * n; ++i) start_idx[i] = 0;
    while (true) {
      int f = Dfs(s, 1e9);
      if (f == 0) break;
      ans++;
    }
  }
  cout << ans << "\n";

  return 0;
}