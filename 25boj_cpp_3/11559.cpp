// Puyo Puyo
// https://www.acmicpc.net/problem/11556

#include <bits/stdc++.h>

#define ll long long

using namespace std;

char arr[12][6];
bool mark[12][6];
bool vis[12][6];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OOR(int x, int y) { return x < 0 || x >= 12 || y < 0 || y >= 6; }

bool Mark() {
  bool ok = false;
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 6; ++j) {
      vis[i][j] = false;
    }
  }
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 6; ++j) {
      if (arr[i][j] == '.') continue;
      if (vis[i][j]) continue;

      queue<pair<int, int>> que;
      que.emplace(i, j);
      vis[i][j] = true;
      vector<pair<int, int>> vv = {{i, j}};

      while (que.size()) {
        int x, y;
        tie(x, y) = que.front();
        que.pop();

        for (int k = 0; k < 4; ++k) {
          int nx = x + dx[k], ny = y + dy[k];
          if (OOR(nx, ny)) continue;
          if (arr[nx][ny] != arr[i][j]) continue;
          if (vis[nx][ny]) continue;
          vis[nx][ny] = true;
          vv.emplace_back(nx, ny);
          que.emplace(nx, ny);
        }
      }

      if (vv.size() >= 4) {
        for (auto [x, y] : vv) {
          mark[x][y] = true;
        }
        ok = true;
      }
    }
  }

  return ok;
}

void Update() {
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 6; ++j) {
      if (mark[i][j]) {
        arr[i][j] = '.';
        mark[i][j] = false;
      }
    }
  }

  for (int j = 0; j < 6; ++j) {
    for (int i = 11; i >= 0; --i) {
      if (arr[i][j] == '.') continue;
      int k = i;
      while (k + 1 < 12 && arr[k + 1][j] == '.') {
        swap(arr[k][j], arr[k + 1][j]);
        k++;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 6; ++j) {
      cin >> arr[i][j];
    }
  }

  int ans = 0;
  while (true) {
    if (Mark() == false) break;
    ans++;
    Update();
  }

  cout << ans << "\n";

  return 0;
}