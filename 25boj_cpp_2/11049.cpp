// 행렬 곱셈 순서 
// https://www.acmicpc.net/problem/11049

#include <bits/stdc++.h>

using namespace std;

int n;

pair<int, int> arr[505];
int dp[505][505];

int Solve(int i, int j) {
  if (i == j) return 0;
  if (dp[i][j] != 0) return dp[i][j];

  int ret = (1LL << 31) - 1;
  for (int k = i; k < j; ++k) {
    ret = min(ret, Solve(i, k) + Solve(k + 1, j) + arr[i].first * arr[k].second * arr[j].second);
  }
  dp[i][j] = ret;
  return dp[i][j];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;

  cout << Solve(0, n - 1) << "\n";

  return 0;
}