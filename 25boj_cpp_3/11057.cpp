// 오르막 수
// https://www.acmicpc.net/problem/11057

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 10007;
int n;

int dp[1005][10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i <= 9; ++i) dp[1][i] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j <= 9; ++j) {
      for (int k = 0; k <= j; ++k) {
        dp[i][j] += dp[i - 1][k];
        dp[i][j] %= kMod;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= 9; ++i) {
    ans += dp[n][i];
    ans %= kMod;
  }

  cout << ans << "\n";

  return 0;
}