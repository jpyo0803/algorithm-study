//
// Kriii Board
// Problem: https://www.acmicpc.net/problem/11058
//

#include <iostream>

#define MODE 1  // 0 = Memoization, 1 = Tabulation

using namespace std;
const int MAX{100};
int N;
uint64_t dp[MAX + 1];

#if (MODE == 0)
bool filled[MAX + 1];
uint64_t memo_method(int i) {
  if (i < 1) return 0;
  if (i == 1) return 1;

  if (filled[i]) return dp[i];

  dp[i] = max(dp[i], memo_method(i - 1) + 1);
  for (int j = 3; j < i; j++) {
    dp[i] = max(dp[i], memo_method(i - j) * (j - 1));
  }
  filled[i] = true;
  return dp[i];
}
#else
uint64_t tabulate_method(int n) {
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;

  for (int i = 4; i <= n; i++) {
    dp[i] = max(dp[i], dp[i - 1] + 1);
    for (int j = 3; j < i; j++) {
      dp[i] = max(dp[i], dp[i - j] * (j - 1));
    }
  }
  return dp[n];
}
#endif

int main() {
  cin >> N;
#if (MODE == 0)
  cout << memo_method(N);
#else
  cout << tabulate_method(N);
#endif
  return 0;
}
