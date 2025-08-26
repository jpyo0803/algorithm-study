// 연구소 
// https://www.acmicpc.net/problem/14502

#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[10][10];
bool vis[10][10];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int Solve(int d) {
  int ret = 0;
  if (d == 3) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        vis[i][j] = false;
      }
    }

    queue<pair<int, int>> que;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (arr[i][j] == 2) {
          que.emplace(i, j);
          vis[i][j] = true;
        }
      }
    }

    while (que.size()) {
      int x, y;
      tie(x, y) = que.front();
      que.pop();

      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (arr[nx][ny] != 0) continue;
        if (vis[nx][ny]) continue;
        vis[nx][ny] = true;
        que.emplace(nx, ny);
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (arr[i][j] != 0) continue;
        if (vis[i][j]) continue;
        ret++;
      }
    }

    return ret;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] != 0) continue;
      arr[i][j] = 1;
      ret = max(ret, Solve(d + 1));
      arr[i][j] = 0;
    }
  }
  return ret;
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

  cout << Solve(0) << "\n";

  return 0;
}