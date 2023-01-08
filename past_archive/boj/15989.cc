//
// 1, 2, 3 Addtion 4
// Problem: https://www.acmicpc.net/problem/15989
//

#include <cstdio>
#include <iostream>

#define MODE 1  // 0 = Memo, 1 = Tabu

#if (MODE == 1)
#include <vector>
#endif

using namespace std;
const int MAX_SIZE{10000};
int T, N;
int dp[MAX_SIZE + 1][4];

#if (MODE == 0)
bool filled[MAX_SIZE + 1][4];
int memo_method(int i, int j) {
  if (i < 0 || j < 1) return 0;
  if (i == 0 || j == 1) return 1;
  if (filled[i][j]) return dp[i][j];

  dp[i][j] = memo_method(i, j - 1) + memo_method(i - j, j);
  filled[i][j] = true;
  return dp[i][j];
}
#else
void tabulate_method(int n) {
  dp[0][1] = dp[0][2] = dp[0][3] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i][1] = 1;
  }
  for (int j = 1; j <= 3; j++) {
    for (int i = 1; i <= n; i++) {
      dp[i][j] = dp[i][j - 1] + dp[i - j][j];
    }
  }
}
#endif
int main() {
  scanf("%d", &T);
#if (MODE == 1)
  vector<int> queries;
  int max_n = 1;
#endif

  for (int tc = 0; tc < T; tc++) {
    scanf("%d", &N);
#if (MODE == 0)
    printf("%d\n", memo_method(N, 3));
#else
    queries.push_back(N);
    if (max_n < N) {
      max_n = N;
    }
#endif
  }

#if (MODE == 1)
  tabulate_method(max_n);
  for (auto query : queries) {
    printf("%d\n", dp[query][3]);
  }
#endif
  return 0;
}
