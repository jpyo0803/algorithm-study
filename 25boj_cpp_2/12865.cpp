// 평범한 배낭 
// https://www.acmicpc.net/problem/12865

#include <bits/stdc++.h>

using namespace std;

int n, k;

int dp[105][100005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;

  // initialize
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= 100000; ++j) {
      dp[i][j] = 1e9; // 1e9 means not possible
    }
  }
   
  dp[0][0] = 0;

  int ans = 0;
  // dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v] + w), where j - v >= 0
  for (int i = 1; i <= n; ++i) {
    int w, v;
    cin >> w >> v;
    for (int j = 0; j <= 100000; ++j) {
      int x = 1e9;
      if (j - v >= 0) x = dp[i - 1][j - v];
      dp[i][j] = min(dp[i - 1][j], x + w);
      if (dp[i][j] <= k && j > ans) ans = j;
    }
  }

  cout << ans << "\n";

  return 0;
}