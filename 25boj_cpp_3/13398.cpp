// 연속합 2
// https://www.acmicpc.net/problem/13398

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100005];
int dp[100005][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];

  int ans = arr[0];
  dp[0][0] = arr[0];

  for (int i = 1; i < n; ++i) {
    dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]);
    dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);
    ans = max({ans, dp[i][0], dp[i][1]});
  }

  cout << ans << "\n";

  return 0;
}