// 앱 
// https://www.acmicpc.net/problem/7579

#include <bits/stdc++.h>

using namespace std;

int n, m;

int ss[105];
int cc[105];

int dp[105][10005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> ss[i];
  for (int i = 1; i <= n; ++i) cin >> cc[i];

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= 10000; ++j) {
      dp[i][j] = -1;
    }
  }
  
  int ans = 1e9;
  dp[0][0] = 0;  
  for (int i = 1; i <= n; ++i) {
    int s = ss[i];
    int c = cc[i];
    for (int j = 0; j <= 10000; ++j) {
      int a, b;
      a = b = -1;
      if (dp[i - 1][j] != -1) a = dp[i - 1][j];
      if (j - c >= 0 && dp[i - 1][j - c] != -1) b = dp[i - 1][j - c] + s;
      if (a != -1 || b != -1) {
        dp[i][j] = max(a, b);
      }
      if (dp[i][j] >= m) {
        ans = min(ans, j);
      }
    }
  }

  cout << ans << "\n";

  return 0;
}