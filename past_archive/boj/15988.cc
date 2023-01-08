//
// 1, 2, 3 Addition 3
// Problem: https://www.acmicpc.net/problem/15988
//

#include <cstdio>
#include <iostream>

#define MODE 1  // 0 = Memoization, 1 = Tabulation

using namespace std;
const int MAX_SIZE{1000000};
const int MOD{1000000009};
int T, N;
uint32_t dp[MAX_SIZE + 1];

#if (MODE == 0)
bool filled[MAX_SIZE + 1];
int32_t memo_method(int i) {
  if (filled[i]) return dp[i];

  for (int j = 3; j >= 1; j--) {
    dp[i] += (memo_method(i - j) % MOD);
  }
  dp[i] %= MOD;
  filled[i] = true;
  return dp[i];
}
#else
int n_max = 3;
int32_t tabulate_method(int n) {
  if (n <= n_max) return dp[n];

  for (int i = n_max + 1; i <= n; i++) {
    for (int j = 3; j >= 1; j--) {
      dp[i] += dp[i - j] % MOD;
    }
    dp[i] %= MOD;
  }
  n_max = n;
  return dp[n];
}
#endif

int main() {
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

#if (MODE == 0)
  filled[1] = filled[2] = filled[3] = true;
#endif
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    scanf("%d", &N);
#if (MODE == 0)
    printf("%u\n", memo_method(N));
#else
    printf("%u\n", tabulate_method(N));
#endif
  }
  return 0;
}
