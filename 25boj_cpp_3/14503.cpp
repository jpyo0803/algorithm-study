// 로봇 청소기
// https://www.acmicpc.net/problem/14503

#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, d;
int arr[55][55];
bool visited[55][55];

// d = N(0), E(1), S(2), W(3)
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool OutOfRange(int x, int y) {
  return x < 0 || y < 0 || x >= n || y >= m;
}

int Rotate(int d) {
  if (d == 0) return 3;
  else if (d == 1) return 0;
  else if (d == 2) return 1;
  return 2;
}

bool CanMoveBehind(int x, int y, int d) {
  int nx = x - dx[d];
  int ny = y - dy[d];
  if (OutOfRange(nx, ny)) return false;
  if (arr[nx][ny] == 1) return false;
  return true;
} 

bool CheckFront(int x, int y, int d) {
  int nx = x + dx[d];
  int ny = y + dy[d];
  if (OutOfRange(nx, ny)) return false;
  if (arr[nx][ny] == 1) return false;
  if (visited[nx][ny]) return false;
  return true;
}

bool CheckAround(int x, int y) {
  bool ok = false;
  for (int i = 0; i < 4; ++i) {
    if (CheckFront(x, y, i)) ok = true; 
  }
  return ok;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> x >> y >> d;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
    }
  }

  int ans = 1;
  visited[x][y] = true;

  while (true) {
    bool ok = CheckAround(x, y);
    if (!ok) {
      if (CanMoveBehind(x, y, d)) {
        x -= dx[d];
        y -= dy[d];
      } else {
        break;
      }
    } else {
      d = Rotate(d);
      if (CheckFront(x, y, d)) {
        x += dx[d];
        y += dy[d];
        ans++;
        visited[x][y] = true;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}