// 벽 부수고 이동하기 2
// https://www.acmicpc.net/problem/14442

#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

char arr[1005][1005];
bool visited[1005][1005][12]; // initialized false

bool OutOfRange(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
    }
  }

  int ans = -1;
  queue<tuple<int, int, int, int>> q; // x, y, broken, cost
  q.emplace(0, 0, 0, 0);
  visited[0][0][0] = true;

  while (q.empty() == false) {
    int x, y, broken, cost;
    tie(x, y, broken, cost) = q.front();
    q.pop();

    if (x == n - 1 && y == m - 1) {
      ans = cost + 1;
      break; // path with lowest cose will arrive first
    }

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (OutOfRange(nx, ny)) continue;
      if (arr[nx][ny] == '0') {
        if (visited[nx][ny][broken]) continue;
        visited[nx][ny][broken] = true;
        q.emplace(nx, ny, broken, cost + 1);
      } else {
        // '1'
        if (broken >= k) continue;
        if (visited[nx][ny][broken + 1]) continue;
        visited[nx][ny][broken + 1] = true;
        q.emplace(nx, ny, broken + 1, cost + 1);
      }
    }
  }

  cout << ans << "\n";

  return 0;
}