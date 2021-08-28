//
// 2 x n tiling
// Problem : https://www.acmicpc.net/problem/11726
//

#include <iostream>

#define MODE 1  // 0 = memoization, 1 = tabulation

using namespace std;

int N;
int dp[1001];
const int div_mod = 10007;

#if (MODE == 0)
int memo_tiling_2n(int n) {
  if (dp[n] != 0) return dp[n];

  if (n == 1 || n == 2) {
    dp[n] = n;
    return dp[n];
  }

  dp[n] =
      ((tiling_2n(n - 1) % div_mod) + (tiling_2n(n - 2) % div_mod)) % div_mod;
  return dp[n];
}
#else
int tabulate_tiling_2n(int n) {
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= N; i++) {
    dp[i] = ((dp[i - 1] % div_mod) + (dp[i - 2] % div_mod)) % div_mod;
  }

  return dp[n];
}
#endif

int main() {
  cin >> N;
#if (MODE == 0)
  cout << tiling_2n(N);
#else
  cout << tabulate_tiling_2n(N);
#endif
}