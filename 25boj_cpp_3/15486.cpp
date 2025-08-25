// 퇴사 2
// https://www.acmicpc.net/problem/15486

#include <bits/stdc++.h>

using namespace std;

int n;

int dp[1500005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  
  for (int i = 0; i <= n; ++i) {
    int t, p;
    cin >> t >> p;
    dp[i] = max(dp[i], i - 1 >= 0 ? dp[i - 1] : 0);
    if (i + t > n) continue;
    dp[i + t] = max(dp[i + t], dp[i] + p);
  }

  cout << dp[n] << "\n";

  return 0;
}