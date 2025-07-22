// 1, 2, 3 더하기
// https://www.acmicpc.net/problem/9095

#include <bits/stdc++.h>

using namespace std;

int t;
int dp[12];

int Solve(int x) {
  if (x < 0) return 0;
  if (x == 0) return 1;
  if (dp[x] != -1) return dp[x];

  dp[x] = 0;
  for (int i = 1; i <= 3; ++i) {
    dp[x] += Solve(x - i);
  }
  return dp[x];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i <= 10; ++i) dp[i] = -1;

  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << Solve(n) << "\n";
  }

  return 0;
}