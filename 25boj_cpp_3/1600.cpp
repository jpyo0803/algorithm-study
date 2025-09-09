// 말이 되고픈 원숭이
// https://www.acmicpc.net/problem/1600

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int k, w, h;
int arr[205][205];
int dist[205][205][35];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dx2[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy2[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool OutOfRange(int x, int y) {
  return x < 0 || x >= h || y < 0 || y >= w;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> k >> w >> h;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> arr[i][j];
      for (int m = 0; m <= k; ++m) dist[i][j][m] = -1;
    }
  }

  queue<tuple<int, int, int>> que;
  que.emplace(0, 0, k);
  dist[0][0][k] = 0;

  int ans = -1;
  while (que.size()) {
    int x, y, k;
    tie(x, y, k) = que.front();
    que.pop();

    if (x == h - 1 && y == w - 1) {
      ans = dist[x][y][k];
      break;
    }

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (OutOfRange(nx, ny)) continue;
      if (dist[nx][ny][k] != -1) continue;
      if (arr[nx][ny] == 1) continue;
      dist[nx][ny][k] = dist[x][y][k] + 1;
      que.emplace(nx, ny, k);
    }

    if (k > 0) {
      for (int i = 0; i < 8; ++i) {
        int nx = x + dx2[i], ny = y + dy2[i];
        if (OutOfRange(nx, ny)) continue;
        if (dist[nx][ny][k - 1] != -1) continue;
        if (arr[nx][ny] == 1) continue;
        dist[nx][ny][k - 1] = dist[x][y][k] + 1;
        que.emplace(nx, ny, k - 1);
      }
    }
  }
  cout << ans << "\n";

  return 0;
}