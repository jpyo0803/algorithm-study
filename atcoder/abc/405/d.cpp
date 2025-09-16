// D - Escape Route (ABC)
// https://atcoder.jp/contests/abc405/tasks/abc405_d

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int h, w;

char arr[1005][1005];

bool OutOfRange(int x, int y) { return x < 0 || x >= h || y < 0 || y >= w; }

int dx[4] = {0, 0, 1, -1};  // E, W, S, W
int dy[4] = {1, -1, 0, 0};

char dir[4] = {'<', '>', '^', 'v'};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> h >> w;

  queue<pair<int, int>> que;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == 'E') {
        que.emplace(i, j);
      }
    }
  }


  while (que.size()) {
    int x, y;
    tie(x, y) = que.front();
    que.pop();

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (OutOfRange(nx, ny)) continue;
      if (arr[nx][ny] != '.') continue;
      arr[nx][ny] = dir[i];
      que.emplace(nx, ny);
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << arr[i][j];
    }
    cout << "\n";
  }

  return 0;
}