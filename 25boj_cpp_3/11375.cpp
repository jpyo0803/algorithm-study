// 열혈강호 
// https://www.acmicpc.net/problem/11375

#include <bits/stdc++.h>

using namespace std;

int n, m;
int level[2005];

int s, t;

vector<int> adj_list[2005];
int cap[2005][2005];
int flow[2005][2005];
int start_idx[2005];

bool Bfs() {
  for (int i = 0; i <= n + m + 1; ++i) level[i] = -1;

  queue<int> que;
  level[s] = 0;
  que.push(s);

  while (que.size()) {
    int u = que.front();
    que.pop();

    for (auto v : adj_list[u]) {
      if (level[v] != -1) continue; // already visited
      if (cap[u][v] == flow[u][v]) continue; // cannot flow more
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

  cin >> n >> m;
  s = 0; // source
  t = n + m + 1; // sink
  for (int u = 1; u <= n; ++u){
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

  for (int i = 1; i <= n; ++i) {
    adj_list[s].push_back(i);
    cap[s][i] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    adj_list[i + n].push_back(t);
    cap[i + n][t] = 1;
  }

  int ans = 0;
  while (Bfs()) {
    for (int i = 0; i <= n + m + 1; ++i) start_idx[i] = 0;

    while (true) {
      int f = Solve(s, 2e9);
      if (f == 0) break;
      ans += f;
    }
  }

  cout << ans << "\n";

  return 0;
}