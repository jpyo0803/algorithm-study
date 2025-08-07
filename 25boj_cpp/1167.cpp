// 트리의 지름
// https://www.acmicpc.net/problem/1167

#include <bits/stdc++.h>

using namespace std;

int n;

vector<pair<int, int>> adj_list[100005];

pair<int, int> Solve(int u, int acc, int prev) {
  auto ret = make_pair(u, acc);

  for (auto e : adj_list[u]) {
    int v = e.first;
    int cost = e.second;
    if (v == prev) continue;
    auto result = Solve(v, acc + cost, u);
    if (result.second > ret.second) ret = result;
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int u, v, c;
    cin >> u;
    while (true) {
      cin >> v;
      if (v == -1) break;
      cin >> c;
      adj_list[u].emplace_back(v, c);
    }
  }

  pair<int, int> result;
  result = Solve(1, 0, -1);

  auto ans = Solve(result.first, 0, -1);
  cout << ans.second << "\n";

  return 0;
}