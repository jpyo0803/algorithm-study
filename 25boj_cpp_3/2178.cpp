// 미로 탐색 
// https://www.acmicpc.net/problem/2178

#include <bits/stdc++.h>

using namespace std;

int n, m;
char arr[105][105];
int dist[105][105];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
      dist[i][j] = -1;
    }
  }

  queue<pair<int, int>> que;
  que.emplace(0, 0);
  dist[0][0] = 0;

  int ans;
  while (que.size()) {
    int ux, uy;
    tie(ux, uy) = que.front();
    que.pop();

    if (ux == n - 1 && uy == m - 1) {
      ans = dist[ux][uy];
      break;
    }

    for (int i = 0; i < 4; ++i) {
      int vx = ux + dx[i];
      int vy = uy + dy[i];
      if (vx < 0 || vy < 0 || vx >= n || vy >= m) continue;
      if (dist[vx][vy] != -1) continue;
      if (arr[vx][vy] == '0') continue;
      dist[vx][vy] = dist[ux][uy] + 1;
      que.emplace(vx, vy);
    }
  }

  cout << ans + 1 << "\n";

  return 0;
}