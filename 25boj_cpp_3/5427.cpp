// 불
// https://www.acmicpc.net/problem/5427

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int w, h;
int OOR(int x, int y) { return x < 0 || x >= h || y < 0 || y >= w; }

int Solve() {
  cin >> w >> h;

  vector<vector<char>> arr(h, vector<char>(w));
  vector<vector<int>> dist(h, vector<int>(w, -1));

  int sx, sy;

  vector<pair<int, int>> sv, fv, tmp;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == '@') {
        sx = i, sy = j;
        arr[i][j] = '.';
      } else if (arr[i][j] == '*') {
        fv.emplace_back(i, j);
      }
    }
  }

  sv.emplace_back(sx, sy);
  dist[sx][sy] = 0;

  int ans = -1;

  while (true) {
    for (auto [x, y] : fv) {
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOR(nx, ny)) continue;
        if (arr[nx][ny] == '#') continue;
        if (arr[nx][ny] == '*') continue;
        arr[nx][ny] = '*';
        tmp.emplace_back(nx, ny);
      }
    }
    fv.swap(tmp);
    tmp.clear();

    for (auto [x, y] : sv) {
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOR(nx, ny)) {
          ans = dist[x][y] + 1;
          break;
        }
        if (arr[nx][ny] != '.') continue;
        if (dist[nx][ny] != -1) continue;
        dist[nx][ny] = dist[x][y] + 1;
        tmp.emplace_back(nx, ny);
      }
      if (ans != -1) break;
    }
    if (ans != -1 || tmp.empty()) break;

    sv.swap(tmp);
    tmp.clear();
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int res = Solve();
    if (res == -1)
      cout << "IMPOSSIBLE\n";
    else
      cout << res << "\n";
  }

  return 0;
}