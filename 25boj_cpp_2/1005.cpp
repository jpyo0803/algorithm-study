// ACM Craft
// https://www.acmicpc.net/problem/1005

#include <bits/stdc++.h>

using namespace std;

int t, n, k, w;

int dp[1005];
int cost[1005];
vector<int> adj_list[1005];

int Solve(int u) {
  if (u == w) return cost[w];
  if (dp[u] != -1) return dp[u];

  int ret = -1e9;
  for (auto v : adj_list[u]) {
    ret = max(ret, Solve(v));
  }
  dp[u] = ret + cost[u];
  return dp[u];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> n >> k;
    
    for (int i = 0; i < n; ++i) {
      cin >> cost[i];
      dp[i] = -1;
      adj_list[i].clear();
    }
    for (int i = 0; i < k; ++i) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      adj_list[x].push_back(y);
    }

    
    cin >> w;
    w--; 
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, Solve(i));
    }

    cout << ans << "\n";
  }

  return 0;
}