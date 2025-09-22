// 로봇 
// https://www.acmicpc.net/problem/13901

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int r, c, k, x, y;
bool obs[1005][1005];
bool vis[1005][1005];
int dirs[4];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool OOR(int x, int y) {
  return x < 0 || x >= r || y < 0 || y >= c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> r >> c;
  cin >> k;
  while (k--) {
    int x, y;
    cin >> x >> y;
    obs[x][y] = true;
  }

  cin >> x >> y;
  for (int i = 0; i < 4; ++i) { 
    cin >> dirs[i];
    dirs[i]--;
  }
  
  int dir = 0;
  vis[x][y] = true;
  int blk_cnt = 0;
  while (blk_cnt < 4) {
    int nx = x + dx[dirs[dir]], ny = y + dy[dirs[dir]];
    if (OOR(nx, ny) || obs[nx][ny] || vis[nx][ny]) {
      dir = (dir + 1) % 4;
      blk_cnt++;
    } else {
      vis[nx][ny] = true;
      x = nx, y = ny;
      blk_cnt = 0;
    }
  }

  cout << x << " " << y << "\n";

  return 0;
}