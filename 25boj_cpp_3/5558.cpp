// チーズ (Cheese)
// https://www.acmicpc.net/problem/5558

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int h, w, n;

char arr[1005][1005];
int dist[1005][1005];

int sx, sy;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OOR(int x, int y) { return x < 0 || x >= h || y < 0 || y >= w; }

int Solve(int t) {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      dist[i][j] = -1;
    }
  }

  queue<pair<int, int>> que;
  que.emplace(sx, sy);
  dist[sx][sy] = 0;

  int ans = 1e9;
  while (que.size()) {
    int x, y;
    tie(x, y) = que.front();
    que.pop();

    if (arr[x][y] - '0' == t) {
      ans = dist[x][y];
      sx = x, sy = y;
      break;
    }

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (OOR(nx, ny)) continue;
      if (arr[nx][ny] == 'X') continue;
      if (dist[nx][ny] != -1) continue;
      dist[nx][ny] = dist[x][y] + 1;
      que.emplace(nx, ny);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> h >> w >> n;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == 'S') {
        sx = i, sy = j;
        arr[i][j] = '.';
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += Solve(i);
  }
  cout << ans << "\n";

  return 0;
}