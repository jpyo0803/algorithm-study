// 장난감 조립
// https://www.acmicpc.net/problem/2637

#include <bits/stdc++.h>

using namespace std;

int n, m;

map<int, int> adj_list[105];
map<int, int> dp[105];

map<int, int> Solve(int u) {
  map<int, int> ret;
  if (adj_list[u].empty()) {
    ret[u] = 1;
    return ret;
  }

  if (dp[u].size()) return dp[u];

  for (auto e : adj_list[u]) {
    int v, k;
    tie(v, k) = e;
    auto res = Solve(v);
    for (auto f : res) {
      int a, b;
      tie(a, b) = f;
      ret[a] += b * k;
    }
  }

  dp[u] = ret;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, k;
    cin >> x >> y >> k;
    adj_list[x][y] = k;
  }

  auto ans = Solve(n);
  for (auto e : ans) {
    cout << e.first << " " << e.second << "\n";
  }

  return 0;
}