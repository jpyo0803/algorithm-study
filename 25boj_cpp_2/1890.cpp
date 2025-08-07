// 점프 
// https://www.acmicpc.net/problem/1890

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[105][105];

long long dp[105][105];

long long Solve(int x, int y) {
  if (x == n - 1 && y == n - 1) return 1;
  if (x >= n || y >= n) return 0;
  if (arr[x][y] == 0) return 0; 
  if (dp[x][y] != -1) return dp[x][y];

  dp[x][y] = Solve(x + arr[x][y], y) + Solve(x, y + arr[x][y]);
  return dp[x][y];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
      dp[i][j] = -1;
    }
  }

  cout << Solve(0, 0) << "\n";

  return 0;
}