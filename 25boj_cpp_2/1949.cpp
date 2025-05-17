// 우수 마을
// https://www.acmicpc.net/problem/1949

#include <bits/stdc++.h>

using namespace std;

int n;

int dp[10005][2];
vector<int> adj_list[10005];
int arr[10005];

int Solve(int u, bool chosen, int p) {
  if (dp[u][chosen] != -1) return dp[u][chosen];

  int ret = chosen ? arr[u] : 0;

  for (auto v : adj_list[u]) {
    if (p == v) continue;
    
    if (chosen) ret += Solve(v, false, u);
    else ret += max(Solve(v, false, u), Solve(v, true, u));
  }
  dp[u][chosen] = ret;
  return dp[u][chosen];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    dp[i][0] = dp[i][1] = -1;
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  cout << max(Solve(1, false, -1), Solve(1, true, -1)) << "\n";

  return 0;
}