// 양
// https://www.acmicpc.net/problem/3184

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int r, c;

char arr[255][255];
bool vis[255][255];

bool OOR(int x, int y) {
  return x < 0 || x >= r || y < 0 || y >= c;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

pair<int, int> Solve(int x, int y) {
  pair<int, int> ret = {arr[x][y] == 'o', arr[x][y] == 'v'};
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (OOR(nx, ny)) continue;
    if (arr[nx][ny] == '#') continue;
    if (vis[nx][ny]) continue;
    vis[nx][ny] = true;
    auto res = Solve(nx, ny);
    ret.first += res.first;
    ret.second += res.second;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    for  (int j = 0; j < c; ++j) {
      cin >> arr[i][j];
    }
  } 

  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (arr[i][j] == '#' || vis[i][j]) continue;
      vis[i][j] = true;
      auto res = Solve(i, j);
      if (res.first > res.second) ans1 += res.first;
      else ans2 += res.second;
    }
  }

  cout << ans1 << " " << ans2 << "\n";

  return 0;
}