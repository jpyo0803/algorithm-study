// 빙산
// https://www.acmicpc.net/problem/2573

#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[305][305];
int tarr[305][305];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OutOfRange(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

bool Simulate() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] == 0)
        tarr[i][j] = 0;
      else {
        int zcnt = 0;
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          if (OutOfRange(ni, nj)) continue;
          if (arr[ni][nj] == 0) zcnt++;
        }
        tarr[i][j] = max(arr[i][j] - zcnt, 0);
      }
    }
  }

  int nzcnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      arr[i][j] = tarr[i][j];
      if (arr[i][j] > 0) nzcnt++;
    }
  }

  return nzcnt > 0;  // true means no more simulation is possible
}

bool vis[305][305];

void Dfs(int x, int y) {
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (OutOfRange(nx, ny)) continue;
    if (arr[nx][ny] == 0) continue;
    if (vis[nx][ny]) continue;
    vis[nx][ny] = true;
    Dfs(nx, ny);
  }
}
bool IsMoreThanTwo() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      vis[i][j] = false;
    }
  }

  int cnt = 0;
  for (int i = 0; i < n && cnt <= 1; ++i) {
    for (int j = 0; j < m && cnt <= 1; ++j) {
      if (vis[i][j] == false && arr[i][j] > 0) {
        vis[i][j] = true;
        Dfs(i, j);
        cnt++;
      }
    }
  }
  return cnt >= 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  int nzcnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] > 0) nzcnt++;
    }
  }

  int ans = 0;
  int t = 0;
  while (true) {
    if (IsMoreThanTwo()) {
      ans = t;
      break;
    }
    if (Simulate() == false) break;
    t++;
  }
  cout << ans << "\n";

  return 0;
}