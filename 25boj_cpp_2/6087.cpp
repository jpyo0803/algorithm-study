// 레이저 통신 
// https://www.acmicpc.net/problem/6087

#include <bits/stdc++.h>

using namespace std;

int h, w;
char arr[105][105];
int dist[105][105][4];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
// EAST, WEST, SOUTH, NORTH

bool CanGo(int x, int y) {
  if (x < 0 || x >= h || y < 0 || y >= w) return false;
  if (arr[x][y] == '*') return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> w >> h;

  vector<pair<int, int>> cs;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == 'C') {
        cs.emplace_back(i, j);
        arr[i][j] = '.';
      }
      for (int k = 0; k < 4; ++k) {
        dist[i][j][k] = 1e9;
      }
    }
  }

  // pair<int, Info>
  priority_queue<pair<int, tuple<int, int, int>>> pq;
  for (int dir = 0; dir < 4; ++dir) {
    pq.emplace(0, tuple<int,int,int>(cs[0].first, cs[0].second, dir));
  }

  while (pq.empty() == false) {
    auto e = pq.top();
    pq.pop();
    int cost = -e.first;
    int ux = get<0>(e.second);
    int uy = get<1>(e.second);
    int dir = get<2>(e.second);
    // cout << ux + 1 << ", " << uy + 1 << ", " << dir << ", " << cost << endl;

    if (dist[ux][uy][dir] <= cost) continue;
    dist[ux][uy][dir] = cost;
    // cout << ux + 1 << ", " << uy + 1 << ", " << dir << ", " << cost <<  " | after" <<  endl;

    int vx, vy;

    // do not deflect
    vx = ux + dx[dir];
    vy = uy + dy[dir];
    if (CanGo(vx, vy) && dist[vx][vy][dir] > cost) {
      // dist[vx][vy][dir] = cost;
      pq.emplace(-cost, tuple<int,int,int>(vx, vy, dir));
    }

    // deflect
    vector<int> next_dirs;
    if (dir == 0 || dir == 1) next_dirs = {2, 3};
    else next_dirs = {0, 1};

    // cout << dir << " -> " << next_dirs[0] << ", " << next_dirs[1] << endl;

    for (auto next_dir : next_dirs) {
      vx = ux + dx[next_dir];
      vy = uy + dy[next_dir];
      if (CanGo(vx, vy) && dist[vx][vy][dir] > cost + 1) {
        // dist[vx][vy][next_dir] = cost + 1;
        pq.emplace(-(cost + 1), tuple<int,int,int>(vx, vy, next_dir));
      }
    }
  }

  int ans = 1e9;
  for (int i = 0; i < 4; ++i) {
    ans = min(ans, dist[cs[1].first][cs[1].second][i]);
  }
  cout << ans << "\n";

  return 0;
}