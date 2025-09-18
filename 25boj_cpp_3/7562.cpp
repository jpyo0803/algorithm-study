// 나이트의 이동
// https://www.acmicpc.net/problem/7562

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int t, n;

int dist[305][305];

bool OOR(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= n;
}

int Solve() {
  cin >> n;
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dist[i][j] = -1;
    }
  }

  queue<pair<int, int>> que;
  que.emplace(sx, sy);
  dist[sx][sy] = 0;

  int ans = 0;
  while (que.size()) {
    int x, y;
    tie(x, y) = que.front();
    que.pop();

    if (x == tx && y == ty) {
      ans = dist[x][y];
      break;
    }

    for (int i = 0; i < 8; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (OOR(nx, ny)) continue;
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

  cin >> t;
  while (t--) {
    cout << Solve() << "\n";
  }

  return 0;
}