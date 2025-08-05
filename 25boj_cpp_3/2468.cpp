// 안전 영역 
// https://www.acmicpc.net/problem/2468

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[105][105];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[105][105];

bool OutOfRange(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= n;
}

void Dfs(int x, int y, int h) {
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (OutOfRange(nx, ny)) continue;
    if (arr[nx][ny] <= h) continue;
    if (visited[nx][ny]) continue;
    visited[nx][ny] = true;
    Dfs(nx, ny, h);
  }
}

int Solve() {
  int ans = 0;
  
  for (int h = 0; h <= 100; ++h) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        visited[i][j] = false;
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (arr[i][j] <= h) continue;
        if (visited[i][j]) continue;
        visited[i][j] = true;
        Dfs(i, j, h);
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }

  cout << Solve() << "\n";

  return 0;
}