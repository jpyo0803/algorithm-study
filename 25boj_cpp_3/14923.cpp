// 미로 탈출 
// https://www.acmicpc.net/problem/14923

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m;
int arr[1005][1005];
int dist[1005][1005][2];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OOR(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  int hx, hy, ex, ey;
  cin >> hx >> hy >> ex >> ey;
  hx--, hy--, ex--, ey--;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
      dist[i][j][0] = dist[i][j][1] = 1e9;
    }
  }


  queue<tuple<int, int, int>> que;
  que.emplace(hx, hy, 0);
  dist[hx][hy][0] = 0;

  while (que.size()) {
    int x, y, z;
    tie(x, y, z) = que.front();
    que.pop();

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (OOR(nx, ny)) continue;
      if (z == 0) {
        if (arr[nx][ny] == 1) {
          if (dist[nx][ny][1] == 1e9) {
            dist[nx][ny][1] = dist[x][y][0] + 1;
            que.emplace(nx, ny, 1);
          }
        } else {
          if (dist[nx][ny][0] == 1e9) {
            dist[nx][ny][0] = dist[x][y][0] + 1;
            que.emplace(nx, ny, 0);
          }
        }
      } else {
        if (arr[nx][ny] == 0) {
          if (dist[nx][ny][1] == 1e9) {
            dist[nx][ny][1] = dist[x][y][1] + 1;
            que.emplace(nx, ny, 1);
          }
        }
      }
    }
  }

  int ans = min(dist[ex][ey][0], dist[ex][ey][1]);
  if (ans == 1e9) cout << "-1\n";
  else cout << ans << "\n";

  return 0;
}