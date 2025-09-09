// 달이 차오른다, 가자.
// https://www.acmicpc.net/problem/1194

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m;
char arr[55][55];
int dist[55][55][70];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OutOfRange(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  int sx = -1, sy;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == '0') {
        sx = i, sy = j;
        arr[i][j] = '.';
      }
      for (int k = 0; k < (1 << 6); ++k) {
        dist[i][j][k] = -1;
      }
    }
  }

  queue<tuple<int, int, char>> que;
  que.emplace(sx, sy, 0);
  dist[sx][sy][0] = 0;

  int ans = -1;
  while (que.size()) {
    int x, y;
    char k;
    tie(x, y, k) = que.front();
    que.pop();

    if (arr[x][y] == '1') {
      if (ans == -1) {
        ans = dist[x][y][k];
        break;
      }
    }

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      char c = arr[nx][ny];
      if (OutOfRange(nx, ny)) continue;
      if (c == '#') continue;
      if (c >= 'A' && c <= 'F') {
        int ord = c - 'A';
        if ((k & (1 << ord)) && dist[nx][ny][k] == -1) {
          dist[nx][ny][k] = dist[x][y][k] + 1;
          que.emplace(nx, ny, k);
        }
      } else if (c >= 'a' && c <= 'f') {
        int ord = c - 'a';
        int nk = k | (1 << ord);
        if (dist[nx][ny][nk] == -1) {
          dist[nx][ny][nk] = dist[x][y][k] + 1;
          que.emplace(nx, ny, nk);
        }
      } else {
        if (dist[nx][ny][k] == -1) {
          dist[nx][ny][k] = dist[x][y][k] + 1;
          que.emplace(nx, ny, k);
        }
      }
    }
  }

  cout << ans << "\n";

  return 0;
}