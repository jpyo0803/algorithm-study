// 음악프로그램
// https://www.acmicpc.net/problem/2623

#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> adj_list[1005];
int visited[1005];
bool visited2[1005];

int Dfs(vector<int>& ans, int u, int seq) {
  for (auto v : adj_list[u]) {
    if (visited2[v]) return -1;
    if (visited[v] != 0) continue;
    visited[v] = seq;
    visited2[v] = true;
    int res = Dfs(ans, v, seq);
    visited2[v] = false;
    if (res == -1) return -1;
  }
  ans.push_back(u);
  return 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    int u = -1;
    while (x--) {
      int v;
      cin >> v;
      if (u != -1) {
        adj_list[u].push_back(v);
      }
      u = v;
    }
  }

  vector<int> ans;
  int seq = 1;
  for (int i = 1; i <= n; ++i) {
    if (visited[i] == 0) {
      visited[i] = seq;
      int res = Dfs(ans, i, seq);
      if (res == -1) {
        ans.clear();
        break;
      }
      seq++;
    }
  }

  if (ans.empty()) cout << "0\n";
  else {
    for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i] << "\n";
  }

  return 0;
}