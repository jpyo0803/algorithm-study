// LCS
// https://www.acmicpc.net/problem/9251

#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];

int na, nb;
string a, b;

int Solve(int i, int j) {
  if (i < 1 || j < 1) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  int ret = 0;
  ret = max(ret, Solve(i - 1, j));
  ret = max(ret, Solve(i, j - 1));
  ret = max(ret, Solve(i - 1, j - 1) + (a[i - 1] == b[j - 1] ? 1 : 0));

  dp[i][j] = ret;
  return dp[i][j];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> a;
  cin >> b;
  
  na = a.length();
  nb = b.length();

  for (int i = 0; i <= na; ++i) {
    for (int j = 0; j <= nb; ++j) {
      dp[i][j] = -1;
    }
  }

  int ans = Solve(na, nb);

  cout << ans << "\n";

  return 0;
}