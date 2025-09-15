// 빵집 
// https://www.acmicpc.net/problem/3109

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int r, c;

char arr[10005][505];
bool vis[10005][505];

int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};

int OOR(int x, int y) {
  return x < 0 || x >= r || y < 0 || y >= c;
}

bool Solve(int x, int y) {
  if (y == c - 1) return true;

  for (int i = 0; i < 3; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (OOR(nx, ny)) continue;
    if (arr[nx][ny] == 'x') continue;
    if (vis[nx][ny]) continue;
    vis[nx][ny] = true;
    if (Solve(nx, ny)) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> arr[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < r; ++i) {
    if (Solve(i, 0)) ans++;
  }
  cout << ans << "\n";

  return 0;
}