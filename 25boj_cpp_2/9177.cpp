// 단어 섞기
// https://www.acmicpc.net/problem/9177

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[205][205];
string a, b, c;

int Solve(int i, int j) {
  if (i < 0 || j < 0) return 0;
  if (i == 0 && j == 1) return b[0] == c[0];
  if (j == 0 && i == 1) return a[0] == c[0];

  if (dp[i][j] != -1) return dp[i][j];

  int ret = 0;
  if (a[i - 1] == c[i + j - 1]) {
    ret = Solve(i - 1, j);
  }
  if (b[j - 1] == c[i + j - 1]) {
    ret |= Solve(i, j - 1);
  }
  dp[i][j] = ret;
  return dp[i][j];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a >> b >> c;
    int len_a = a.length(), len_b = b.length(), len_c = c.length();

    for (int j = 0; j <= len_a; ++j) {
      for (int k = 0; k <= len_b; ++k) {
        dp[j][k] = -1;
      }
    }

    string ans = Solve(len_a, len_b) == 1 ? "yes" : "no";

    cout << "Data set " << i + 1 << ": " << ans << "\n";
  }

  return 0;
}