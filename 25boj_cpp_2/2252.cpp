// 줄 세우기
// https://www.acmicpc.net/problem/2252

#include <bits/stdc++.h>

using namespace std;

int n, m;
bool has_rel[32005];
bool visited[32005];
vector<int> adj_list[32005];

void Dfs(vector<int>& ans, int x) {
  visited[x] = true;
  for (auto y : adj_list[x]) {
    if (visited[y]) continue;
    Dfs(ans, y);
  }
  ans.push_back(x);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    has_rel[a] = has_rel[b] = true;
    adj_list[a].push_back(b);
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (has_rel[i] == false) continue;
    if (visited[i] == true) continue;
    visited[i] = true;
    Dfs(ans, i);
  }

  for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i] + 1 << " ";
  for (int i = 0; i < n; ++i) {
    if (has_rel[i] == false) {
      cout << i + 1 << " ";
    }
  }
  cout << "\n";

  return 0;
}