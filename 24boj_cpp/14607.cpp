// 피자 (Large)
// https://www.acmicpc.net/problem/14607

#include <bits/stdc++.h>

using namespace std;

long long dp[1000010];

long long Solve(long long n) {
  if (n == 1) return 0;
  if (n <= 1e6 && dp[n] != -1) return dp[n];

  long long half_n = n / 2;
  long long res = Solve(half_n) + Solve(n - half_n) + (half_n * (n - half_n));
  if (n <= 1e6) dp[n] = res;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i <= 1e6; i++) {
    dp[i] = -1;
  }

  int n;
  cin >> n;

  cout << Solve(n) << "\n";

  return 0;
}