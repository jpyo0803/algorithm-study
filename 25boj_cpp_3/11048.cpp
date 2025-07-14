// 이동하기 
// https://www.acmicpc.net/problem/11048

#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[1005][1005];
int dp[1005][1005];

int Solve(int x, int y) {
  if (x < 0 || y < 0) return 0;
  if (dp[x][y] != -1) return dp[x][y];

  int& ret = dp[x][y];
  ret = max(ret, Solve(x - 1, y));
  ret = max(ret, Solve(x, y - 1));
  ret = max(ret, Solve(x - 1, y - 1));
  ret += arr[x][y];
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
      dp[i][j] = -1;
    }
  }

  cout << Solve(n - 1, m - 1) << "\n";;

  return 0;
}