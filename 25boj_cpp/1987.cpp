// 알파벳
// https://www.acmicpc.net/problem/1987

#include <bits/stdc++.h>

using namespace std;

bool visited[256];
char arr[25][25];

int r, c;

int ans = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void Solve(int x, int y, int depth) {
  ans = max(ans, depth);

  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
    if (visited[arr[nx][ny]]) continue;
    visited[arr[nx][ny]] = true;
    Solve(nx, ny, depth + 1);
    visited[arr[nx][ny]] = false;
  }
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

  visited[arr[0][0]] = true;
  Solve(0, 0, 1);

  cout << ans << "\n";

  return 0;
}