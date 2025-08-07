// 제곱수의 합
// https://www.acmicpc.net/problem/1699

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[100005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    dp[i] = 1e9;
    for (long long j = 1; j * j <= i; ++j) {
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }
  cout << dp[n] << "\n";

  return 0;
}