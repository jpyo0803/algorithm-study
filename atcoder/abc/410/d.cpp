// D - XOR Shortest Walk (ABC)
// https://atcoder.jp/contests/abc410/tasks/abc410_d

#include <bits/stdc++.h>

using namespace std;

int n, m;

set<pair<int, int>> adj_list[1030][1030]; // u, state

bool visited[1030][1030];

void Dfs(int a, int j) {
  visited[a][j] = true;

  for (auto e : adj_list[a][j]) {
    int b, k;
    tie(b, k) = e;
    if (visited[b][k]) continue;
    Dfs(b, k);
  }
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    // (a) --w--> (b)
    for (int j = 0; j < (1 << 10); ++j) {
      int k = j ^ w;
      adj_list[a][j].insert({b, k});
    }
  }

  Dfs(1, 0);

  int ans = -1;
  for (int i = 0; i < (1 << 10); ++i) {
    if (visited[n][i]) {
      ans = i;
      break;
    }
  }

  cout << ans << "\n";

  return 0;
}