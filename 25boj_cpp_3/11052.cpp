// 카드 구매하기 
// https://www.acmicpc.net/problem/11052

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1005];
int dp[1005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> arr[i];

  for (int i = 1; i <= n; ++i) {
    dp[i] = arr[i];
    for (int j = i - 1; j >= 1; --j) {
      dp[i] = max(dp[i], dp[j] + arr[i - j]);
    }
  }

  cout << dp[n] << "\n";

  return 0;
}