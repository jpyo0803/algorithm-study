//
// Bridge Construction
// Problem: https://www.acmicpc.net/problem/1010
//

#include <iostream>

#define MODE 0  // 0 = memoization, 1 = tabulation

using namespace std;

const int MAX_SIZE{30};
int dp[MAX_SIZE][MAX_SIZE];
int T, N, M;

#if (MODE == 0)
bool filled[MAX_SIZE][MAX_SIZE];

int memo_method(int i, int j) {
  if (i == 1) return j;
  if (filled[i][j]) return dp[i][j];

  dp[i][j] = 0;
  for (int k = i - 1; k < j; k++) {
    dp[i][j] += memo_method(i - 1, k);
  }
  filled[i][j] = true;
  return dp[i][j];
}

#else
int tabulate_method(int n, int m) {
  for (int i = 1; i <= m; i++) {
    dp[1][i] = i;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= m; j++) {
      dp[i][j] = 0;
      for (int k = i - 1; k < j; k++) {
        dp[i][j] += dp[i - 1][k];
      }
    }
  }

  return dp[n][m];
}
#endif

int main() {
  cin >> T;
#if (MODE == 0)
  cout << "Memoization" << endl;
#else
  cout << "Tabulation" << endl;
#endif
  for (int t = 0; t < T; t++) {
    cin >> N >> M;
#if (MODE == 0)
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j <= M; j++) {
        filled[i][j] = false;
      }
    }
    cout << memo_method(N, M) << endl;
#else
    cout << tabulate_method(N, M) << endl;
#endif
  }
  return 0;
}
