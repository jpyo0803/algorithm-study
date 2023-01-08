//
// Biggest square
// Problem: https://www.acmicpc.net/problem/1915
//

#include <iostream>
#define MODE 1  // 0 = memoization, 1 = tabulation
using namespace std;
const int MAX_SIZE{1000};
int N, M;

bool field[MAX_SIZE + 1][MAX_SIZE + 1];
int dp[MAX_SIZE + 1][MAX_SIZE + 1];
string line;

#if (MODE == 0)
bool filled[MAX_SIZE + 1][MAX_SIZE + 1];
int memo_method(int i, int j) {
  if (!field[i][j]) return 0;
  if (i == 0 || j == 0) return 0;
  if (filled[i][j]) return dp[i][j];

  dp[i][j] = min(memo_method(i - 1, j), memo_method(i, j - 1));
  dp[i][j] = min(dp[i][j], memo_method(i - 1, j - 1));
  dp[i][j] += 1;
  filled[i][j] = true;
  return dp[i][j];
}
#else
int tabulate_method(int n, int m) {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!field[i][j]) continue;
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
      dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
      dp[i][j] += 1;
      if (ans < dp[i][j]) {
        ans = dp[i][j];
      }
    }
  }
  return ans * ans;
}
#endif
int main() {
  cin.tie(NULL);
  cin.sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> line;
    for (int j = 1; j <= line.length(); j++) {
      field[i][j] = (line[j - 1] == '1');
    }
  }
#if (MODE == 0)
  cout << "Memoization" << endl;
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      int ret = memo_method(i, j);
      if (ans < ret) {
        ans = ret;
      }
    }
  }
  cout << ans * ans;
#else
  cout << "Tabulation" << endl;
  cout << tabulate_method(N, M);
#endif
  return 0;
}