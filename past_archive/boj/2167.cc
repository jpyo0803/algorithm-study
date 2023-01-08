//
// Sum of 2-D Array
// Problem: https://www.acmicpc.net/problem/2167
//

#include <cstdio>

#define MODE 0  // 0 = memoization, 1 = tabulation

const int MAX_SIZE{300};
int N, M, K, i, j, x, y;
int arr[MAX_SIZE + 1][MAX_SIZE + 1];
int dp[MAX_SIZE + 1][MAX_SIZE + 1];

#if (MODE == 0)
bool filled[MAX_SIZE + 1][MAX_SIZE + 1];

int memo_method(int i, int j) {
  if (i == 0 || j == 0) return 0;
  if (filled[i][j]) return dp[i][j];

  dp[i][j] = memo_method(i - 1, j) + memo_method(i, j - 1) -
             memo_method(i - 1, j - 1) + arr[i][j];
  filled[i][j] = true;
  return dp[i][j];
}

#else
void tabulate_method(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
    }
  }
}
#endif

int main() {
  scanf("%d%d", &N, &M);
  for (int ii = 1; ii <= N; ii++) {
    for (int jj = 1; jj <= M; jj++) {
      scanf("%d", &arr[ii][jj]);
    }
  }

#if (MODE == 0)
  printf("Memoization\n");
#else
  printf("Tabulation\n");
  tabulate_method(N, M);
#endif
  scanf("%d", &K);
  for (int ii = 0; ii < K; ii++) {
    scanf("%d%d%d%d", &i, &j, &x, &y);
#if (MODE == 0)
    printf("%d\n", memo_method(x, y) - memo_method(x, j - 1) -
                       memo_method(i - 1, y) + memo_method(i - 1, j - 1));
#else
    printf("%d\n", dp[x][y] - dp[x][j - 1] - dp[i - 1][y] + dp[i - 1][j - 1]);
#endif
  }
  return 0;
}
