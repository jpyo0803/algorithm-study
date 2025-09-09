// 미로 만들기
// https://www.acmicpc.net/problem/1347

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  int x = 0, y = 0, dir = 0;

  set<pair<int, int>> ss;
  ss.insert({x, y});

  int mi_x = 0, mi_y = 0;
  int ma_x = 0, ma_y = 0;
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    if (c == 'F') {
      x += dx[dir], y += dy[dir];
      mi_x = min(mi_x, x), mi_y = min(mi_y, y);
      ma_x = max(ma_x, x), ma_y = max(ma_y, y);
      ss.insert({x, y});
    } else if (c == 'L') {
      dir = (dir + 4 - 1) % 4;
    } else {
      dir = (dir + 1) % 4;
    }
  }

  int offx = -mi_x, offy = -mi_y;
  int h = ma_x - mi_x + 1, w = ma_y - mi_y + 1;
  vector<vector<char>> ans(h, vector<char>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      ans[i][j] = '#';
    }
  }

  for (auto [x, y] : ss) {
    ans[x + offx][y + offy] = '.';
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << ans[i][j];
    }
    cout << "\n";
  }
  return 0;
}