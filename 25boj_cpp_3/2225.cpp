// 합분해 
// https://www.acmicpc.net/problem/2225

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9;

int n, k;
int dp[205][205];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;

  for (int i = 0; i <= n; ++i) {
    dp[i][1] = 1;
  }

  for (int i = 2; i <= k; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int g = 0; g <= j; ++g) {
        dp[j][i] += dp[g][i - 1];
        dp[j][i] %= kMod;
      }
    }
  }

  cout << dp[n][k] << "\n";

  return 0;
}