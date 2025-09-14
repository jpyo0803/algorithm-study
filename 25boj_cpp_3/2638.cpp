// 치즈
// https://www.acmicpc.net/problem/2638

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m;

bool OOR(int x, int y) { return x < 0 || x > n + 1 || y < 0 || y > m + 1; }

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int arr[105][105];
bool vis[105][105];
int touch[105][105];

int cnt = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == 1) cnt++;
    }
  }

  int t = 0;
  while (cnt > 0) {
    for (int i = 0; i <= n + 1; ++i) {
      for (int j = 0; j <= m + 1; ++j) {
        vis[i][j] = false;
        touch[i][j] = 0;
      }
    }

    queue<pair<int, int>> que;
    que.emplace(0, 0);
    vis[0][0] = true;

    while (que.size()) {
      int x, y;
      tie(x, y) = que.front();
      que.pop();

      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOR(nx, ny)) continue;
        if (arr[nx][ny] == 1) {
          touch[nx][ny]++;
          continue;
        }
        if (vis[nx][ny]) continue;
        vis[nx][ny] = true;
        que.emplace(nx, ny);
      }
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (touch[i][j] >= 2) {
          arr[i][j] = 0;
          cnt--;
        }
      }
    }
    t++;
  }

  cout << t << "\n";

  return 0;
}