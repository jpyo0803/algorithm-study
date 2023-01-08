//
// Sum of squares
// Problem: https://www.acmicpc.net/problem/1699
//

#include <cmath>
#include <iostream>

#define MODE 1  // 0 = memoization, 1 = tabulation

using namespace std;

int N;
int dp[100001];
const int INF{100000000};

#if (MODE == 0)
int memo_method(int i) {
  if (dp[i]) return dp[i];

  if (i == 0) return 0;
  if (i == 1) return 1;

  dp[i] = INF;
  int base = 1;
  while (base * base <= i) {
    int candidate = memo_method(i - (base * base)) + 1;
    if (candidate < dp[i]) {
      dp[i] = candidate;
    }
    base += 1;
  }
  return dp[i];
}
#else
int tabulation(int n) {
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    dp[i] = INF;

    int base = 1;
    while (base * base <= i) {
      int candidate = dp[i - (base * base)] + 1;
      if (candidate < dp[i]) {
        dp[i] = candidate;
      }
      base += 1;
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
  cout << tabulation(N);
#endif
  return 0;
}
