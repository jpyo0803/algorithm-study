// 피보나치 수
// https://www.acmicpc.net/problem/2747

#include <bits/stdc++.h>

using namespace std;

long long dp[50];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  dp[0] = 0;
  dp[1] = 1;

  int n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  cout << dp[n] << "\n";

  return 0;
}