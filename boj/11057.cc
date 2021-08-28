//
// Non-decreasing number
// Problem: https://www.acmicpc.net/problem/11057
//

#include <iostream>

#define MODE 1  // 0 = memoization, 1 = tabulation

using namespace std;

const int MAX_SIZE{1001};
const int div_mod{10007};

int N;
int dp[MAX_SIZE][10];

#if (MODE == 0)
int memo_method(int i, int j) {
  if (i == 0) {
    dp[i][j] = 1;
    return dp[i][j];
  }
  if (dp[i][j]) return dp[i][j];

  dp[i][j] = 0;
  for (int k = 0; k <= j; k++) {
    dp[i][j] += memo_method(i - 1, k) % div_mod;
  }
  dp[i][j] %= div_mod;
  return dp[i][j];
}
#else
int tabulate_method(int n) {
  for (int i = 0; i < 10; i++) dp[0][i] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      dp[i][j] = 0;
      for (int k = 0; k <= j; k++) {
        dp[i][j] += dp[i - 1][k] % div_mod;
      }
      dp[i][j] %= div_mod;
    }
  }
  return dp[n][9];
}
#endif

int main() {
  cin >> N;
#if (MODE == 0)
  cout << memo_method(N, 9);
#else
  cout << tabulate_method(N);
#endif

  return 0;
}