// 보물섬 
// https://www.acmicpc.net/problem/2589

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int dist[55][55];
char arr[55][55];
int n, m;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OOR(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m;
}

void ResetDist() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dist[i][j] = -1;
    }
  }
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
      if (arr[i][j] == 'W') continue;
      ResetDist();

      int ma = 0;
      queue<pair<int, int>> que;
      dist[i][j] = 0;
      que.emplace(i, j);
      while (que.size()) {
        int x, y;
        tie(x, y) = que.front();
        que.pop();

        ma = max(ma, dist[x][y]);

        for (int k = 0; k < 4; ++k) {
          int nx = x + dx[k], ny = y + dy[k];
          if (OOR(nx, ny)) continue;
          if (arr[nx][ny] == 'W') continue;
          if (dist[nx][ny] != -1) continue;
          dist[nx][ny] = dist[x][y] + 1;
          que.emplace(nx, ny);
        }
      }

      ans = max(ans, ma);
    }
  }

  cout << ans << "\n";

  return 0;
}