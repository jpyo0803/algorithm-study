// 로봇
// https://www.acmicpc.net/problem/1726

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int m, n;
int arr[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int dist[105][105][4];

int GetCorrectDir(int d) {
  if (d == 1) return 3;
  else if (d == 2) return 1;
  else if (d == 3) return 0;
  return 2;
}

bool OutOfRange(int x, int y) {
  return x < 0 || x >= m || y < 0 || y >= n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
      for (int k = 0; k < 4; ++k) dist[i][j][k] = -1;
    }
  }

  int rx, ry, rd, tx, ty, td;
  cin >> rx >> ry >> rd;
  rx--, ry--;
  rd = GetCorrectDir(rd);

  cin >> tx >> ty >> td;
  tx--, ty--;
  td = GetCorrectDir(td);

  queue<tuple<int, int, int>> que;
  que.emplace(rx, ry, rd);
  dist[rx][ry][rd] = 0;

  int ans = -1;

  while (que.size()) {
    int x, y, d;
    tie(x, y, d) = que.front();
    que.pop();

    if (x == tx && y == ty && d == td) {
      ans = dist[x][y][d];
      break;
    }

    if (dist[x][y][(d + 1) % 4] == -1) {
      dist[x][y][(d + 1) % 4] = dist[x][y][d] + 1;
      que.emplace(x, y, (d + 1) % 4);
    }

    if (dist[x][y][(d - 1 + 4) % 4] == -1) {
      dist[x][y][(d - 1 + 4) % 4] = dist[x][y][d] + 1;
      que.emplace(x, y, (d - 1 + 4) % 4);
    }
    // 0 = S, 1 = W, 2 = N, 3 = E
    for (int k = 1; k <= 3; ++k) {
      int nx = x + dx[d] * k, ny = y + dy[d] * k;
      if (OutOfRange(nx, ny)) break;
      if (arr[nx][ny] == 1) break;
      if (dist[nx][ny][d] != -1) continue;
      dist[nx][ny][d] = dist[x][y][d] + 1;
      que.emplace(nx, ny, d);
    }
  }

  cout << ans << "\n";

  return 0;
}