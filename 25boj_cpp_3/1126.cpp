// 같은 탑 
// https://www.acmicpc.net/problem/1126

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[250005][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i <= 250000; ++i) dp[i][0] = dp[i][1] = -1;
  dp[0][0] = 0;

  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;

    int c = i % 2;
    int p = (i + 1) % 2;
    for (int j = 0; j <= 250000; ++j) {
      int a = -1, b = -1;
      if (j + x <= 250000) a = dp[j + x][p];
      if (j - x >= 0) {
        if (dp[j - x][p] != -1) {
          b = dp[j - x][p] + x;
        }
      } else if (j - x >= -250000) {
        if (dp[abs(j - x)][p] != -1) {
          b = dp[abs(j - x)][p] + j;
        }
      }
      dp[j][c] = max({dp[j][p], a, b});
    }
  }

  if (dp[0][n % 2] == 0) cout << "-1\n";
  else cout << dp[0][n % 2] << "\n";

  return 0;
}