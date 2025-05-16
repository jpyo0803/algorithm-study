// 사회망 서비스(SNS)
// https://www.acmicpc.net/problem/2533

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e6 + 5;

int n;
vector<int> adj_list[kMax];
int dp[kMax][2];

int Solve(int u, int p, bool chosen) {
  if (dp[u][chosen] != -1) return dp[u][chosen];

  int ret = chosen ? 1 : 0;
  for (auto v : adj_list[u]) {
    if (v == p) continue;
    int a = 1e9, b = 1e9;
    // if chosen, then next can be both
    // if not chosen, then next must be chosen
    a = Solve(v, u, true);
    if (chosen) b = Solve(v, u, false);
    ret += min(a, b);
  }

  dp[u][chosen] = ret;
  return dp[u][chosen];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  for (int i = 1; i <= n; ++i) dp[i][0] = dp[i][1] = -1;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  } 

  cout << min(Solve(1, -1, false), Solve(1, -1, true)) << "\n";

  return 0;
}