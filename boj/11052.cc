//
// Card purchase
// Problem: https://www.acmicpc.net/problem/11052
//

#include <iostream>

#define MODE 0  // 0 = memoization, 1 = tabulation

using namespace std;

int N;
const int NUM_CARD{1000};
int price[NUM_CARD + 1];
int dp[NUM_CARD + 1];

#if (MODE == 0)
int memo_method(int i) {
  if (i == 0) return 0;
  if (dp[i]) return dp[i];

  dp[i] = price[i];
  int j = 0;
  while (j <= i - j) {
    dp[i] = max(dp[i], memo_method(j) + memo_method(i - j));
    j++;
  }
  return dp[i];
}

#else
int tabulate_method(int n) {
  for (int i = 1; i <= n; i++) {
    dp[i] = price[i];
    int j = 0;
    while (j <= i - j) {
      dp[i] = max(dp[i], dp[j] + dp[i - j]);
      j++;
    }
  }
  return dp[n];
}
#endif

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> price[i];
  }
#if (MODE == 0)
  cout << memo_method(N);
#else
  cout << tabulate_method(N);
#endif
  return 0;
}