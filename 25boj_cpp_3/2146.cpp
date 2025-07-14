// 다리 만들기
// https://www.acmicpc.net/problem/2146

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[105][105];
int group[105][105];
int dist[105][105];

void ResetDist() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dist[i][j] = -1;
    }
  }
}

bool OutOfRange(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }
bool Visited(int x, int y) { return dist[x][y] != -1; }
bool IsSea(int x, int y) { return arr[x][y] == 0; }

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void MarkGroup(int x, int y, int gid) {
  group[x][y] = gid;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (OutOfRange(nx, ny) || Visited(nx, ny) || IsSea(nx, ny)) continue;
    dist[nx][ny] = dist[x][y] + 1; // does not have to increase
    MarkGroup(nx, ny, gid);
  }
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

  ResetDist();
  int gid = 0;

  vector<pair<int, int>> sv; // start
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (Visited(i, j) || IsSea(i, j)) continue;
      gid++;
      dist[i][j] = 0;
      MarkGroup(i, j, gid);
      sv.emplace_back(i, j);
    }
  }

  int ans = 1e9;

  for (auto e : sv) {
    int sx, sy;
    tie(sx, sy) = e;
    ResetDist();
    
    deque<pair<int, int>> dq;
    dq.emplace_back(sx, sy);
    dist[sx][sy] = 0;

    int gid = group[sx][sy];

    int cand = 1e9;
    while (dq.size()) {
      int ux, uy;
      tie(ux, uy) = dq.front();
      dq.pop_front();
      
      if (group[ux][uy] >= 1 && group[ux][uy] != gid) {
        cand = min(cand, dist[ux][uy]);
        break;
      }

      for (int i = 0; i < 4; ++i) {
        int vx, vy;
        vx = ux + dx[i];
        vy = uy + dy[i];

        if (OutOfRange(vx, vy) || Visited(vx, vy)) continue;
        dist[vx][vy] = dist[ux][uy] + (IsSea(vx, vy) ? 1 : 0);
        if (IsSea(vx, vy)) {
          dist[vx][vy] = dist[ux][uy] + 1;
          dq.emplace_back(vx, vy);
        } else {
          dist[vx][vy] = dist[ux][uy];
          dq.emplace_front(vx, vy);
        }
      }
    }

    ans = min(ans, cand);
  }

  cout << ans << "\n";

  return 0;
}