// 줄세우기
// https://www.acmicpc.net/problem/2631

#include <bits/stdc++.h>

using namespace std;

int n;
int vv[205];

int dp[205];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> vv[i];

  // find a longest subseq
  // 3 7 5 2 6 1 4
  for (int i = n - 1; i >= 0; --i) {
    int maxx = 0;
    for (int j = i + 1; j < n; ++j) {
      if (vv[i] < vv[j]) {
        maxx = max(maxx, dp[j]);
      } 
    }
    dp[i] = maxx + 1;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);

  cout << n - ans << "\n";

  return 0;
}