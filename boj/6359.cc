//
// Druken Sangbum
// Problem: https://www.acmicpc.net/problem/6359
//

#include <cstdio>

#define MODE 1  // 0 = Memoization, 1 = Tabulation

const int MAX_SIZE{100};
int T, N;

bool doors[MAX_SIZE + 1];
int dp[MAX_SIZE + 1];
int dp_next[MAX_SIZE + 1];

#if (MODE == 0)
bool filled[MAX_SIZE + 1];
int memo_method(int i) {
  if (i == 1) return 1;
  if (filled[i]) return dp[i];

  for (int j = i; j <= MAX_SIZE; j += i) {
    doors[j] = !doors[j];
  }
  dp[i] = memo_method(i - 1) + doors[i];
  filled[i] = true;
  return dp[i];
}
#else
void tabulate_method() {
  dp[1] = 1;

  for (int i = 2; i <= MAX_SIZE; i++) {
    for (int j = i; j <= MAX_SIZE; j += i) {
      doors[j] = !doors[j];
    }
    dp[i] = dp[i - 1] + doors[i];
  }
}
#endif
int main() {
  for (int i = 1; i <= MAX_SIZE; i++) {
    doors[i] = true;
  }

  scanf("%d", &T);
#if (MODE == 0)
  printf("Memoization\n");
#else
  printf("Tabulation\n");
  tabulate_method();
#endif
  for (int tc = 0; tc < T; tc++) {
    scanf("%d", &N);
#if (MODE == 0)
    printf("%d\n", memo_method(N));
#else
    printf("%d\n", dp[N]);
#endif
  }
  return 0;
}