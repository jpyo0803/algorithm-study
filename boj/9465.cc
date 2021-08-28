//
// Sticker
// Problem: https://www.acmicpc.net/problem/9465
//

#include <iostream>

#define MODE 1  // 0 = memoization, 1 = tabulation

using namespace std;

const int MAX_SIZE{100000};
int T, N;
int stickers[MAX_SIZE + 1][2];
int dp[MAX_SIZE + 1][2];

int max(int x, int y) { return (x < y) ? y : x; }

#if (MODE == 0)
bool filled[MAX_SIZE + 1][2];
int memo_method(int i, bool j) {
  if (i == 0) return 0;
  if (filled[i][j]) return dp[i][j];

  dp[i][j] =
      max(memo_method(i - 1, j), memo_method(i - 1, !j) + stickers[i][j]);
  filled[i][j] = true;
  return dp[i][j];
}
#else
int tabulate_method(int n) {
  for (int i = 1; i <= n; i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + stickers[i][0]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + stickers[i][1]);
  }
  return max(dp[n][0], dp[n][1]);
}
#endif
int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

#if (MODE == 0)
  cout << "Memoization Method" << endl;
#else
  cout << "Tabulation Method" << endl;
#endif
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N;
    for (int j = 1; j <= N; j++) cin >> stickers[j][0];
    for (int j = 1; j <= N; j++) cin >> stickers[j][1];
#if (MODE == 0)
    for (int j = 1; j <= N; j++) filled[j][0] = filled[j][1] = false;
    cout << max(memo_method(N, 0), memo_method(N, 1)) << endl;
#else
    cout << tabulate_method(N) << endl;
#endif
  }
  return 0;
}
