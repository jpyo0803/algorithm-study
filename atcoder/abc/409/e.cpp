// E - Pair Annihilation (ABC)
// https://atcoder.jp/contests/abc409/tasks/abc409_e

#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> adj_list[100005];
int xarr[100005];
long long ans = 0;

int Solve(int u, int p, int w) {
  int sum = xarr[u];
  for (auto [v, next_w] : adj_list[u]) {
    if (v == p) continue;
    sum += Solve(v, u, next_w);
  }

  ans += (long long)abs(sum) * w;
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> xarr[i];
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    assert(u < v);
    adj_list[u].emplace_back(v, w);
    adj_list[v].emplace_back(u, w);
  }

  Solve(1, -1, 0);
  cout << ans << "\n";

  return 0;
}