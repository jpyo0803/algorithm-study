// 탈출
// https://www.acmicpc.net/problem/3055

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int r, c;
char arr[55][55];
int dist[55][55];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OOR(int x, int y) {
  return x < 0 || x >= r || y < 0 || y >= c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int sx, sy;

  cin >> r >> c;

  vector<pair<int, int>> wv, gv;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> arr[i][j];
      dist[i][j] = -1;
      if (arr[i][j] == '*') wv.emplace_back(i, j);
      else if (arr[i][j] == 'S') {
        gv.emplace_back(i, j);
        arr[i][j] = '.';
        dist[i][j] = 0;
      }
    }
  }

  vector<pair<int, int>> next_wv, next_gv;
  int ans = -1;
  while (true) {
    for (auto e : wv) {
      for (int i = 0; i < 4; ++i) { 
        int nx = e.first + dx[i], ny = e.second + dy[i];
        if (OOR(nx, ny)) continue;
        if (arr[nx][ny] != '.') continue;
        next_wv.emplace_back(nx, ny);
        arr[nx][ny] = '*';
      }
    }

    wv.swap(next_wv);
    next_wv.clear();

    for (auto e : gv) {
      for (int i = 0; i < 4; ++i) { 
        int nx = e.first + dx[i], ny = e.second + dy[i];
        if (OOR(nx, ny)) continue;
        if (arr[nx][ny] == 'X' || arr[nx][ny] == '*') continue;
        if (arr[nx][ny] == 'D') {
          ans = dist[e.first][e.second] + 1;
          break;
        }
        if (dist[nx][ny] != -1) continue;
        next_gv.emplace_back(nx, ny);
        dist[nx][ny] = dist[e.first][e.second] + 1;
      }
      if (ans != -1) break;
    }
    if (ans != -1) break;
    if (next_gv.empty()) break;
    gv.swap(next_gv);
    next_gv.clear();
  }

  if (ans == -1) cout << "KAKTUS\n";
  else cout << ans << "\n";

  return 0;
}