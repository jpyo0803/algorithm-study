// 테트로미노
// https://www.acmicpc.net/problem/14500

#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[505][505];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool vis[505][505];

bool OutOfRange(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m;
}

int Solve(int x, int y, int d) {
  if (d == 3) return arr[x][y];
  vis[x][y] = true;
  int ret = 0;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (OutOfRange(nx, ny)) continue;
    if (vis[nx][ny]) continue;
    ret = max(ret, Solve(nx, ny, d + 1));
  }
  vis[x][y] = false;
  return ret + arr[x][y];
}

int SolveT(int x, int y, int d) {
  if (d == 1) return arr[x][y];
  int sum = 0;
  int cnt = 0;
  int mi = 1e9;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (OutOfRange(nx, ny)) continue;
    int res = SolveT(nx, ny, d + 1);
    mi = min(mi, res);
    sum += res;
    cnt++;
  }
  if (cnt < 3) return 0;
  if (cnt == 4) sum -= mi;

  return sum + arr[x][y];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans = max({ans, Solve(i, j, 0), SolveT(i, j, 0)});
    }
  }

  cout << ans << "\n";

  return 0;
}