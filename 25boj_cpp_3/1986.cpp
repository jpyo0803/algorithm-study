// 체스
// https://www.acmicpc.net/problem/1986

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m;
int k, r, c;

bool arr[1005][1005];
bool occu[1005][1005];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int dx2[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy2[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

bool OutOfRange(int x, int y) { return x < 1 || x > n || y < 1 || y > m; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  cin >> k;

  vector<pair<int, int>> qv, kv, pv;
  while (k--) {
    cin >> r >> c;
    qv.emplace_back(r, c);
    occu[r][c] = true;
  }

  cin >> k;
  while (k--) {
    cin >> r >> c;
    kv.emplace_back(r, c);
    occu[r][c] = true;
  }

  cin >> k;
  while (k--) {
    cin >> r >> c;
    pv.emplace_back(r, c);
    occu[r][c] = true;
  }

  for (auto e : qv) {
    for (int i = 0; i < 8; ++i) {
      int s = 1;
      while (true) {
        int nx = e.first + dx[i] * s;
        int ny = e.second + dy[i] * s;
        if (OutOfRange(nx, ny)) break;
        if (occu[nx][ny] == true) break;
        arr[nx][ny] = true;
        s++;
      }
    }
  }

  for (auto e : kv) {
    for (int i = 0; i < 8; ++i) {
      int nx = e.first + dx2[i];
      int ny = e.second + dy2[i];
      if (OutOfRange(nx, ny)) continue;
      if (occu[nx][ny] == true) continue;
      arr[nx][ny] = true;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (arr[i][j] == false && occu[i][j] == false) ans++;
    }
  }
  cout << ans << "\n";

  return 0;
}