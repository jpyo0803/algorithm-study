// 섬의 개수
// https://www.acmicpc.net/problem/4963

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int w, h;
int arr[55][55];
bool vis[55][55];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool OOR(int x, int y) { return x < 0 || x >= h || y < 0 || y >= w; }

void Solve(int x, int y) {
  for (int i = 0; i < 8; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (OOR(nx, ny)) continue;
    if (arr[nx][ny] == 0) continue;
    if (vis[nx][ny]) continue;
    vis[nx][ny] = true;
    Solve(nx, ny);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> w >> h;

  while (!(w == 0 && h == 0)) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> arr[i][j];
        vis[i][j] = false;
      }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (vis[i][j]) continue;
        if (arr[i][j] == 0) continue;
        vis[i][j] = true;
        Solve(i, j);
        ans++;
      }
    }

    cout << ans << "\n";

    cin >> w >> h;
  }

  return 0;
}