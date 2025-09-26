// D - Goin' to the Zoo (ABC)
// https://atcoder.jp/contests/abc404/tasks/abc404_d

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m;
int cost[12];
int cnt[105];
vector<int> adj[12];

ll Solve(int u, ll sum) {
  if (u == n) {
    for (int i = 0; i < m; ++i) {
      if (cnt[i] < 2) return 1e18;
    }
    return sum;
  }

  ll ret = 1e18;
  for (int i = 0; i < 3; ++i) {
    for (auto v : adj[u]) cnt[v] += i;
    ret = min(ret, Solve(u + 1, sum + cost[u] * i));
    for (auto v : adj[u]) cnt[v] -= i;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> cost[i];
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    while (k--) {
      int a;
      cin >> a;
      adj[a - 1].push_back(i);
    }
  }

  cout << Solve(0, 0) << "\n";

  return 0;
}