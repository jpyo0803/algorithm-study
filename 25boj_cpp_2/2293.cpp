// 동전 1
// https://www.acmicpc.net/problem/2293

#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[105];
int dp[10005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    int c;
    cin >> c;
    for (int j = c; j <= k; ++j) {
      dp[j] += dp[j - c];
    }
  }
  cout << dp[k] << "\n";

  return 0;
}