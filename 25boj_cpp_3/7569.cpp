// 토마토
// https://www.acmicpc.net/problem/7569

#include <bits/stdc++.h>

using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int dist[105][105][105];
int arr[105][105][105];

int m, n, h;

bool OutOfRange(int x, int y, int z) {
  return x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= h;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> m >> n >> h;
  // n x m x h
  queue<tuple<int, int, int>> que;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        cin >> arr[i][j][k];
        if (arr[i][j][k] == 1) {
          que.emplace(i, j, k);
          dist[i][j][k] = 0;
        } else {
          dist[i][j][k] = -1;
        }
      }
    }
  }

  int ans;
  while (que.size()) {
    int z, x, y;
    tie(z, x, y) = que.front();
    que.pop();

    ans = dist[z][x][y];

    for (int i = 0; i < 6; ++i) {
      int nz = z + dz[i];
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (OutOfRange(nx, ny, nz)) continue;
      if (arr[nz][nx][ny] != 0) continue;
      if (dist[nz][nx][ny] != -1) continue;
      dist[nz][nx][ny] = dist[z][x][y] + 1;
      que.emplace(nz, nx, ny);
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        if (arr[i][j][k] == 0 && dist[i][j][k] == -1) {
          cout << "-1\n";
          return 0;
        }
      }
    }
  }

  cout << ans << "\n";

  return 0;
}