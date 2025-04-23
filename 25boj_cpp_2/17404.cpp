// RGB거리 2
// https://www.acmicpc.net/problem/17404

#include <bits/stdc++.h>

using namespace std;

int n;
int costs[1005][3];  // rgb
int dp[1005][3][3];  // index, start, color

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> costs[i][j];
    }
  }

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (i == j)
        dp[0][i][j] = costs[0][i];
      else
        dp[0][i][j] = 1e9;
    }
  }

  for (int i = 1; i < n - 1; ++i) {
    for (int j = 0; j < 3; ++j) {    // start point color
      for (int k = 0; k < 3; ++k) {  // curr color
        int min_cost = 1e9;
        for (int i2 = 0; i2 < 3; ++i2) {  // prev color
          if (k == i2) continue;
          min_cost = min(min_cost, dp[i - 1][j][i2] + costs[i][k]);
        }
        dp[i][j][k] = min_cost;
      }
    }
  }

  int ans = 1e9;
  for (int i = 0; i < 3; ++i) {    // curr color
    for (int j = 0; j < 3; ++j) {  // starting color
      if (i == j) continue;
      for (int k = 0; k < 3; ++k) {  // prev color
        if (i == k) continue;
        ans = min(ans, dp[n - 2][j][k] + costs[n - 1][i]);
      }
    }
  }

  cout << ans << "\n";

  return 0;
}