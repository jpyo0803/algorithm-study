// Minimax Tree
// https://www.acmicpc.net/problem/28472

#include <bits/stdc++.h>

using namespace std;

int n, r, l, q;

vector<int> adj_list[100005];
int ans[100005];

int Solve(int x, int prev, bool maximize) {
  if (ans[x] != -1) return ans[x];
  int ret = maximize ? 0 : 1e9;
  for (auto y : adj_list[x]) {
    if (y == prev) continue;
    ret = maximize ? max(ret, Solve(y, x, false)) : min(ret, Solve(y, x, true));
  }
  ans[x] = ret;
  return ans[x];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> r;
  for (int i = 1; i <= n; ++i) ans[i] = -1;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  cin >> l;
  for (int i = 0; i < l; ++i) {
    int k, t;
    cin >> k >> t;
    ans[k] = t;
  }

  Solve(r, -1, true);

  cin >> q;
  for (int i = 0; i < q; ++i) {
    int a;
    cin >> a;
    cout << ans[a] << "\n";
  }

  return 0;
}