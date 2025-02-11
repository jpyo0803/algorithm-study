// 쉬운 최단거리
// https://www.acmicpc.net/problem/14940

#include <bits/stdc++.h>

using namespace std;

struct Info {
  int x, y, dst;

  Info(int _x, int _y, int _dst) : x(_x), y(_y), dst(_dst) {}
};

int n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  vector<vector<int>> mm(n, vector<int>(m));

  int si = -1, sj;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mm[i][j];
      if (mm[i][j] == 2 && si == -1) {
        si = i;
        sj = j;
      } 
    }
  }

  vector<vector<bool>> visited(n, vector<bool>(m, false));
  vector<vector<int>> dst(n, vector<int>(m, -1));

  queue<Info> que;
  que.emplace(si, sj, 0);

  int dx[4] = {0, 1, -1, 0};
  int dy[4] = {1, 0, 0, -1};

  while (que.empty() == false) {
    auto u = que.front();
    que.pop();

    if (visited[u.x][u.y] == true) continue;
    visited[u.x][u.y] = true;
    dst[u.x][u.y] = u.dst;

    for (int i = 0; i < 4; ++i) {
      int vx = u.x + dx[i];
      int vy = u.y + dy[i];

      if (vx < 0 || vx >= n || vy < 0 || vy >= m) continue;
      if (mm[vx][vy] == 0) continue; 
      if (visited[vx][vy] == true) continue;
      que.emplace(vx, vy, u.dst + 1); 
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (dst[i][j] == -1 && mm[i][j] == 0) {
        dst[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << dst[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}