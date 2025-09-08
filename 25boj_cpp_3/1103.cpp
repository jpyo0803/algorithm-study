// 게임
// https://www.acmicpc.net/problem/1103

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m;
char b[55][55];
bool vis[55][55];
int dp[55][55];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OutOfRange(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int Solve(int x, int y) {
  if (dp[x][y] != -1) return dp[x][y];

  int ret = 0;
  for (int i = 0; i < 4; ++i) {
    int f = b[x][y] - '0';
    int nx = x + f * dx[i];
    int ny = y + f * dy[i];
    if (OutOfRange(nx, ny)) continue;
    if (b[nx][ny] == 'H') continue;
    if (vis[nx][ny]) return 1e9;
    vis[nx][ny] = true;
    ret = max(ret, Solve(nx, ny) + 1);
    vis[nx][ny] = false;
  }

  dp[x][y] = ret;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> b[i][j];
      dp[i][j] = -1;
    }
  }

  int res = Solve(0, 0);
  if (res >= 1e9)
    cout << "-1\n";
  else
    cout << res + 1 << "\n";

  return 0;
}