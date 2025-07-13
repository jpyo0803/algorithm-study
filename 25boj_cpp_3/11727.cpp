// 2×n 타일링 2
// https://www.acmicpc.net/problem/11727

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 10007;

int n;

int dp[1005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  dp[1] = 1;
  dp[2] = dp[1] + 1 + 1;

  for (int i = 3; i <= n; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2] * 2;
    dp[i] %= kMod;
  }

  cout << dp[n] << "\n";

  return 0;
}