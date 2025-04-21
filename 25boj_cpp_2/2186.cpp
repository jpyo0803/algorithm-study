// 문자판
// https://www.acmicpc.net/problem/2186

#include <bits/stdc++.h>

using namespace std;

int n, m, k;
char arr[105][105];
string target;
int dp[105][105][85];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int Solve(int depth, int x, int y) {
  if (depth == target.length() - 1 && arr[x][y] == target[depth]) {
    return 1;  // found 1
  }

  if (arr[x][y] != target[depth]) {
    return 0;
  }

  int delta = target.length() - depth;
  if (dp[x][y][delta] != -1) {
    return dp[x][y][delta];
  }

  int ret = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 1; j <= k; ++j) {
      int nx = x + dx[i] * j;
      int ny = y + dy[i] * j;
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      ret += Solve(depth + 1, nx, ny);
    }
  }

  dp[x][y][delta] = ret;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
      for (int k = 0; k < 85; ++k) {
        dp[i][j][k] = -1;
      }
    }
  }

  cin >> target;

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int ret = Solve(0, i, j);
      ans += ret;
    }
  }

  cout << ans << "\n";

  return 0;
}