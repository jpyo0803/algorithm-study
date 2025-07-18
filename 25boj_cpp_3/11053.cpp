// 가장 긴 증가하는 부분 수열
// https://www.acmicpc.net/problem/11053

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1005];
int arr[1005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> arr[i];

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    
    int prev_max = 0;
    for (int j = 1; j < i; ++j) {
      if (arr[j] < arr[i] && dp[j] > prev_max) {
        prev_max = dp[j];
      }
    }
    dp[i] = prev_max + 1;
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";

  return 0;
}