// 트리의 독립집합
// https://www.acmicpc.net/problem/2213

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[10005];
vector<int> adj_list[10005];
int dp[10005][2];

vector<pair<int, bool>> path[10005][2];

void FindIndependentSet(int u, bool chosen, vector<int>& iset) {
  if (chosen) iset.push_back(u);
  for (auto v : path[u][chosen]) {
    FindIndependentSet(v.first, v.second, iset);
  }
}

int Solve(int u, int p, bool chosen)  {
  if (dp[u][chosen] != -1) return dp[u][chosen];
  int ret = 0;

  for (auto v : adj_list[u]) {
    if (p == v) continue;

    if (chosen) {
      ret += Solve(v, u, false);
      path[u][chosen].emplace_back(v, false);
    } else { 
      int a = Solve(v, u, false);
      int b = Solve(v, u, true);
      if (a > b) {
        ret += a;
        path[u][chosen].emplace_back(v, false);
      } else {
        ret += b;
        path[u][chosen].emplace_back(v, true);
      }
    }
  }

  dp[u][chosen] = ret + (chosen ? arr[u] : 0);
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

  int res_a = Solve(1, -1, false);
  int res_b = Solve(1, -1, true);

  int ans;
  vector<int> iset;
  if (res_a > res_b) {
    ans = res_a;
    FindIndependentSet(1, false, iset);
  } else {
    ans = res_b;
    FindIndependentSet(1, true, iset);
  }

  sort(iset.begin(), iset.end());

  cout << ans << "\n";
  for (auto e : iset) cout << e << " ";

  return 0;
}