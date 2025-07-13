// 쉬운 계단 수 
// https://www.acmicpc.net/problem/10844

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9;
int n;
int dp[105][10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= 9; ++i) dp[1][i] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j <= 9; ++j) {
      if (j - 1 >= 0) {
        dp[i][j] += dp[i - 1][j - 1];
        dp[i][j] %= kMod;
      }
      if (j + 1 <= 9) {
        dp[i][j] += dp[i - 1][j + 1];
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