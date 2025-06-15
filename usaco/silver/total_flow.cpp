// Total Flow (Silver)
// https://www.acmicpc.net/problem/6086

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj_list[55];
int cap[55][55];
int flow[55][55];
int level[55];
int start_idx[55];
int s = 0; // source, 'A'
int t = 'Z' - 'A'; // sink, 'Z'

int C2I(char ch) {
  if ('A' <= ch && ch <= 'Z') return (ch - 'A');
  return (ch - 'a') + 26;
}

bool Bfs() {
  for (int i = 0; i < 52; ++i) level[i] = -1;

  queue<int> que;
  que.push(s);
  level[s] = 0;

  while (que.size()) {
    int u = que.front();
    que.pop();

    for (int i = 0; i < adj_list[u].size(); ++i) {
      int v = adj_list[u][i];
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
    if (level[u] + 1 == level[v] && cap[u][v] > flow[u][v]) {
      int ret = Dfs(v, min(min_flow, cap[u][v] - flow[u][v]));
      if (ret > 0) {
        flow[u][v] += ret;
        flow[v][u] -= ret;
        return ret;
      }
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  bool conn_uv[52]{};
  bool conn_vu[52]{};

  cin >> n;
  for (int i = 0; i < n; ++i) {
    char u, v;
    int c;
    cin >> u >> v >> c;
    u = C2I(u);
    v = C2I(v);

    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
    
    cap[u][v] += c; // just in case duplicated edge is given
    cap[v][u] += c; // just in case duplicated edge is given
  }

  int ans = 0;
  while (Bfs()) {
    for (int i = 0; i < 52; ++i) start_idx[i] = 0;
    while (true) {
      int f = Dfs(s, 2e9);
      if (f == 0) break;
      ans += f;
    }
  }

  cout << ans << "\n";

  return 0;
}