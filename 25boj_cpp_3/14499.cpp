// 주사위 굴리기
// https://www.acmicpc.net/problem/14499

#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, k;
int arr[22][22];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

struct Dice {
  int x, y;

  array<int, 7> f;
  Dice(int _x, int _y) : x(_x), y(_y) {
    for (int i = 1; i < 7; ++i) f[i] = 0;
  }

  int Roll(int dir) {
    int nx = x + dx[dir - 1];
    int ny = y + dy[dir - 1];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) return -1;
    x = nx, y = ny;

    array<int, 7> tf;
    if (dir == 1) {
      tf[1] = f[4], tf[2] = f[2], tf[3] = f[1], tf[4] = f[6], tf[5] = f[5], tf[6] = f[3];
    } else if (dir == 2) {
      tf[1] = f[3], tf[2] = f[2], tf[3] = f[6], tf[4] = f[1], tf[5] = f[5], tf[6] = f[4];
    } else if (dir == 3) {
      tf[1] = f[5], tf[2] = f[1], tf[3] = f[3], tf[4] = f[4], tf[5] = f[6], tf[6] = f[2];
    } else {
      tf[1] = f[2], tf[2] = f[6], tf[3] = f[3], tf[4] = f[4], tf[5] = f[1], tf[6] = f[5];
    }
    f = tf;

    if (arr[x][y] == 0) arr[x][y] = f[6];
    else {
      f[6] = arr[x][y];
      arr[x][y] = 0;
    }
    return f[1];
  }  
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> x >> y >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
    }
  }

  Dice dice(x, y);

  while (k--) {
    int dir;
    cin >> dir;
    int res = dice.Roll(dir);
    if (res != -1) cout << res << "\n";
  }

  return 0;
}