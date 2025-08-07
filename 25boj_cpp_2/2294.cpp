// 동전 2
// https://www.acmicpc.net/problem/2294

#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[105];
int dp[10005];

int Solve(int x) {
  if (x < 0) return 1e9;
  if (x == 0) return 0;
  if (dp[x] != -1) return dp[x];

  dp[x] = 1e9;
  for (int i = 0; i < n; ++i) {
    dp[x] = min(dp[x], Solve(x - arr[i]) + 1);
  }
  return dp[x];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  for (int i = 0; i <= k; ++i) dp[i] = -1;

  int ans = Solve(k);
  if (ans == 1e9) ans = -1;
  cout << ans << "\n";

  return 0;
}