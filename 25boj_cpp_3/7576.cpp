// 토마토 
// https://www.acmicpc.net/problem/7576

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m;
int arr[1005][1005];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dist[1005][1005];

bool OOR(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  queue<pair<int, int>> que;
  
  int cnt = 0;
  cin >> m >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dist[i][j] = -1;
      cin >> arr[i][j];
      if (arr[i][j] == 1) {
        que.emplace(i, j);
        dist[i][j] = 0;
      } else if (arr[i][j] == 0) {
        cnt++;
      }

    }
  }

  int ans;
  while (que.size()) {
    int x, y;
    tie(x, y) = que.front();
    que.pop();

    ans = dist[x][y];

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (OOR(nx, ny)) continue;
      if (arr[nx][ny] != 0) continue;
      if (dist[nx][ny] != -1) continue;
      dist[nx][ny] = dist[x][y] + 1;
      que.emplace(nx, ny);
      cnt--;
    }
  }

  cout << (cnt == 0 ? ans : -1) << "\n";

  return 0;
}