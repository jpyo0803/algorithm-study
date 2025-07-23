// E - Battles in a Row (ABC)
// https://atcoder.jp/contests/abc410/tasks/abc410_e

#include <bits/stdc++.h>

using namespace std;

int N, H, M;
int dp[3005][3005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> H >> M;
  
  dp[0][H] = M;
  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    int a, b;
    cin >> a >> b;
    for (int h = 0; h <= H; ++h) {
      dp[i][h] = -1;
      if (dp[i - 1][h] != -1 && dp[i - 1][h] - b >= 0) dp[i][h] = max(dp[i][h], dp[i - 1][h] - b);
      if (h + a <= H && dp[i - 1][h + a] != -1) dp[i][h] = max(dp[i][h], dp[i - 1][h + a]);
      if (dp[i][h] != -1) ans = i;
    }
  }

  cout << ans << "\n";
  return 0;
}