// 1, 2, 3 더하기 4
// https://www.acmicpc.net/problem/15989

#include <bits/stdc++.h>

using namespace std;

long long dp[10010][4];

int t, n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i][j] = 1;
    }
  }

  for (int i = 4; i <= 10000; ++i) {
    for (int j = 1; j <= 3; ++j) {
      long long sum = 0;
      for (int k = 1; k <= j; ++k) {
        sum += dp[i - j][k];
      }
      dp[i][j] = sum;
    }
  }

  cin >> t;
  while (t--) {
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= 3; ++i) sum += dp[n][i];
    cout << sum << "\n";
  }

  return 0;
}