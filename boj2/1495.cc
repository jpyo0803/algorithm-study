//
// Guitarist
// Problem: https://www.acmicpc.net/problem/1495
//

#include <iostream>

#define MODE 0  // 0 = memoization, 1 = tabulation

using namespace std;
const int MAX_VOL{1000};
const int MAX_SONG{100};
int N, S, M;

int volume[MAX_SONG + 1];
bool dp[MAX_SONG + 1][MAX_VOL + 1];

#if (MODE == 0)
bool filled[MAX_SONG + 1][MAX_VOL + 1];
bool memo_method(int i, int j) {
  if (i == 0) {
    if (j < 0 || j > M) return false;
    return dp[0][j];
  }
  if (filled[i][j]) {
    return dp[i][j];
  }

  dp[i][j] = false;
  if (j - volume[i] >= 0) dp[i][j] = memo_method(i - 1, j - volume[i]);
  if (j + volume[i] <= M) dp[i][j] |= memo_method(i - 1, j + volume[i]);

  filled[i][j] = true;
  return dp[i][j];
}
#else
int tabulate_method(int s, int n) {
  dp[0][s] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= M; j++) {
      if (dp[i - 1][j]) {
        int nj = j - volume[i];
        if (nj >= 0) dp[i][nj] = true;
        nj = j + volume[i];
        if (nj <= M) dp[i][nj] = true;
      }
    }
  }

  int ans{-1};
  for (int i = M; i >= 0; i--) {
    if (dp[n][i]) {
      ans = i;
      break;
    }
  }
  return ans;
}
#endif
int main() {
  cin >> N >> S >> M;
  for (int i = 1; i <= N; i++) {
    cin >> volume[i];
  }

#if (MODE == 0)
  dp[0][S] = true;
  int ans = -1;
  for (int j = M; j >= 0; j--) {
    if (memo_method(N, j)) {
      ans = j;
      break;
    }
  }
  cout << ans;
#else
  cout << tabulate_method(S, N);
#endif
  return 0;
}
