//
// Moving
// Problem: https://www.acmicpc.net/problem/11048
//

#include <iostream>

#define MODE 0  // 0 = Memoization, 1 = tabulation

using namespace std;

const int MAX_SIZE{1000};
int N, M;
int maze[MAX_SIZE + 1][MAX_SIZE + 1];
int dp[MAX_SIZE + 1][MAX_SIZE + 1];

int max(int x, int y) { return (x < y) ? y : x; }

#if (MODE == 0)
bool filled[MAX_SIZE + 1][MAX_SIZE + 1];
int memo_method(int i, int j) {
  if (i == 0 || j == 0) return 0;
  if (filled[i][j]) return dp[i][j];

  dp[i][j] = max(max(memo_method(i - 1, j), memo_method(i, j - 1)),
                 memo_method(i - 1, j - 1)) +
             maze[i][j];
  filled[i][j] = true;
  return dp[i][j];
}
#else
int tabulate_method(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] =
          max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + maze[i][j];
    }
  }
  return dp[n][m];
}
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> maze[i][j];
    }
  }
#if (MODE == 0)
  cout << "Memoization" << endl;
  cout << memo_method(N, M);
#else
  cout << "Tabulation" << endl;
  cout << tabulate_method(N, M);
#endif
  return 0;
}
