// 내리막 길
// https://www.acmicpc.net/problem/1520

#include <bits/stdc++.h>

using namespace std;

int m, n;
int arr[505][505];
int dp[505][505];

// E, W, S, N
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OutOfRange(int x, int y) {
  return x < 0 || y < 0 || x >= m || y >= n;
}

int Solve(int x, int y) {
  if (x == 0 && y == 0) return 1;
  if (dp[x][y] != -1) return dp[x][y];
  
  dp[x][y] = 0;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (OutOfRange(nx, ny)) continue;
    if (arr[x][y] >= arr[nx][ny]) continue;
    dp[x][y] += Solve(nx, ny);
  }
  return dp[x][y];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
      dp[i][j] = -1;
    }
  }

  cout << Solve(m - 1, n - 1) << "\n";

  return 0;
}