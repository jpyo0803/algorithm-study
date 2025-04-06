// 파일 합치기
// https://www.acmicpc.net/problem/11066

/*
  dp[i][j] = total cost merging from i to j
  dp[i][j] = min(dp[i][k] + dp[k + 1, j]), k = l, ..., j - 1
*/

#include <bits/stdc++.h>

using namespace std;

int t, k;
long long dp[505][505];
int arr[505];
int ps[505];

int GetPS(int l, int r) {
  int low = (l - 1 >= 0 ? ps[l - 1] : 0);
  return ps[r] - low;
}

long long Solve(int l, int r) {
  if (l == r) return 0LL;
  if (dp[l][r] != -1) return dp[l][r];

  long long ret = 2e9;
  for (int k = l; k < r; ++k) {
    ret = min(ret, Solve(l, k) + Solve(k + 1, r) + GetPS(l, k) + GetPS(k + 1, r));
  }
  dp[l][r] = ret;
  return dp[l][r];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> t;
  while (t--) {
    cin >> k;

    for (int i = 0; i < k; ++i) {
      cin >> arr[i];
      ps[i] = i - 1 >= 0 ? ps[i - 1] : 0;
      ps[i] += arr[i];
    }

    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < k; ++j) {
        dp[i][j] = (i == j) ? 0 : -1;
      }
    }

    cout << Solve(0, k - 1) << "\n";
  }

  return 0;
}