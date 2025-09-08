// 수영장 만들기
// https://www.acmicpc.net/problem/1113

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m;
int arr[55][55];
bool vis[55][55];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OutOfRange(int x, int y) {
  return x < 0 || x > n + 1 || y < 0 || y > m + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char ch;
      cin >> ch;
      arr[i][j] = ch - '0';
    }
  }

  int ans = 0;

  for (int h = 1; h <= 9; ++h) {
    for (int i = 0; i <= n + 1; ++i) {
      for (int j = 0; j <= m + 1; ++j) {
        vis[i][j] = false;
      }
    }
    queue<pair<int, int>> que;
    que.emplace(0, 0);
    vis[0][0] = true;
    arr[0][0] = h;

    while (que.size()) {
      int x, y;
      tie(x, y) = que.front();
      que.pop();

      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OutOfRange(nx, ny)) continue;
        if (arr[nx][ny] >= h) continue;
        if (vis[nx][ny]) continue;
        arr[nx][ny] = h;
        vis[nx][ny] = true;
        que.emplace(nx, ny);
      }
    }
    
    for (int i = 0; i <= n + 1; ++i) {
      for (int j = 0; j <= m + 1; ++j) {
        if (arr[i][j] < h) {
          ans++;
          arr[i][j] = h;
        }
      }
    }
  }

  cout << ans << "\n";

  return 0;
}