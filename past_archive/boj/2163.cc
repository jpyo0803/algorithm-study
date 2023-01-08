//
// Chocolate Cutting
// Problem: https://www.acmicpc.net/problem/2163
//

#include <iostream>

#define MODE 1  // 0 = memoization, 1 = tabulation

using namespace std;

const int MAX_SIZE{300};
const int INF{100000000};
int N, M;
int dp[MAX_SIZE + 1][MAX_SIZE + 1];

#if (MODE == 0)
int memo_method(int i, int j) {
  if (i == 1 && j == 1) return 0;
  if (dp[i][j]) return dp[i][j];

  dp[i][j] = INF;
  dp[i][j] =
      min(dp[i][j], memo_method(i / 2, j) + memo_method(i - (i / 2), j) + 1);
  dp[i][j] =
      min(dp[i][j], memo_method(i, j / 2) + memo_method(i, j - (j / 2)) + 1);

  return dp[i][j];
}
#else
int tabulate_method(int n, int m) {
  for (int i = 1; i <= m; i++) {
    dp[1][i] = i - 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == 1 && j == 1) continue;
      int res_div_i = INF;
      int res_div_j = INF;

      if (i / 2 > 0) res_div_i = dp[i / 2][j] + dp[i - (i / 2)][j];
      if (j / 2 > 0) res_div_j = dp[i][j / 2] + dp[i][j - (j / 2)];

      dp[i][j] = min(res_div_i, res_div_j) + 1;
    }
  }
  return dp[n][m];
}
#endif

int main() {
  cin >> N >> M;
#if (MODE == 0)
  cout << memo_method(N, M);
#else
  cout << tabulate_method(N, M);
#endif
  return 0;
}