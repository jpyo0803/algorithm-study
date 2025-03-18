// 로봇 조종하기 
// https://www.acmicpc.net/problem/2169

#include <bits/stdc++.h>

using namespace std;

int arr[1010][1010];
int n, m;

int dp[1010][1010][3];

// east, west, north
int dx[3] = {0, 0, -1};
int dy[3] = {1, -1, 0};

// dp[x][y] = max(dp[x][y], dp[px][py]) + arr[x][y], excluding direction from myself

int Solve(int x, int y, int px, int py, int dir) {
  if (x < 0 || x >= n || y < 0 || y >= m) return -1e9;
  if (x == 0 && y == 0) return arr[x][y];
  if (dp[x][y][dir] != -1e9) {
    return dp[x][y][dir];
  }

  int loc_max = -1e9;
  for (int i = 0; i < 3; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx == px && ny == py) continue;
    loc_max = max(loc_max, Solve(nx, ny, x, y, i));
  }
  dp[x][y][dir] = loc_max + arr[x][y];
  return dp[x][y][dir];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
      for (int k = 0; k < 3; ++k) {
        dp[i][j][k] = -1e9;
      }
    }
  }
  

  int ans = -1e9;
  for (int i = 0; i < 3; ++i) {
    ans = max(ans, Solve(n - 1, m - 1, n - 1, m - 1, i));
  }
  cout << ans << "\n";

  return 0;
}