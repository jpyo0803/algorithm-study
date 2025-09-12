// 포도주 시식
// https://www.acmicpc.net/problem/2156

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
int arr[10005];
int dp[10005][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];

  dp[0][0] = 0, dp[0][2] = -1e9;
  dp[0][1] = arr[0];

  int ans = arr[0];
  for (int i = 1; i < n; ++i) {
    dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
    dp[i][1] = dp[i - 1][0] + arr[i];
    dp[i][2] = dp[i - 1][1] + arr[i];
    ans = max({ans, dp[i][0], dp[i][1], dp[i][2]});
  }

  cout << ans << "\n";

  return 0;
}