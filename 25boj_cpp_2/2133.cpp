// 타일 채우기
// https://www.acmicpc.net/problem/2133

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[32];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  dp[0] = 1;
  dp[2] = 3;
  for (int i = 3; i <= n; ++i) {
    if (i % 2 == 0) {
      dp[i] += dp[i - 2] * 3;
      for (int j = 4; j <= i; j += 2) {
        dp[i] += dp[i - j] * 2;
      }
    }
  }

  cout << dp[n] << "\n";

  return 0;
}