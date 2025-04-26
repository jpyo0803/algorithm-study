// 색상환
// https://www.acmicpc.net/problem/2482

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 3;

int n, k;

int dp[1005][1005];

void Reset(){
  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (i == 0) dp[i][j] = 1;
      else dp[i][j] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin >> k;

  Reset();
  
  int ans = 0;
  // first one is chosen as first pick
  for (int i = 1; i <= n; ++i) {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= k; ++i) {
    for (int j = 3; j < n; ++j) {
      dp[i][j] += dp[i][j - 1];
      dp[i][j] %= kMod;
      dp[i][j] += dp[i - 1][j - 2];
      dp[i][j] %= kMod;
    }
  }

  ans += dp[k][n - 1];
  ans %= kMod;

  Reset();
 
  for (int i = 1; i <= k; ++i) {
    for (int j = 2; j <= n; ++j) {
      dp[i][j] += dp[i][j - 1];
      dp[i][j] %= kMod;
      dp[i][j] += dp[i - 1][j - 2];
      dp[i][j] %= kMod;
    }
  }
  ans += dp[k][n];
  ans %= kMod;

  cout << ans << "\n";

  return 0;
}