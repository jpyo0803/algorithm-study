// 로봇 청소기
// https://www.acmicpc.net/problem/4991

#include <bits/stdc++.h>

using namespace std;

int h, w, cnt;

char arr[22][22];
int trash[22][22];
bool visited[22][22];
bool visited2[22][22][1030];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool CanGo(int x, int y) {
  if (x < 0 || x >= h || y < 0 || y >= w) return false;
  if (arr[x][y] == 'x') return false;
  return true;
}

int CountFindable(int x, int y) {
  visited[x][y] = true;

  int ret = 0;
  if (arr[x][y] == '*') {
    ret = 1;
  }

  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (CanGo(nx, ny) == false) continue;
    if (visited[nx][ny]) continue;
    ret += CountFindable(nx, ny);
  }
  return ret;
}

int Solve(int sx, int sy) {
  int term_bm = (1 << cnt) - 1;
  priority_queue<tuple<int, pair<int, int>, int>> pq;  // -cost, pos, bitmask;
  pq.emplace(0, pair<int, int>(sx, sy), 0);

  int ans = 1e9;

  while (pq.empty() == false) {
    auto e = pq.top();
    pq.pop();
    int cost = -get<0>(e);
    int ux = get<1>(e).first;
    int uy = get<1>(e).second;
    int bm = get<2>(e);
    // cout << cost << " / " << ux << " / " << uy << " / " << bm << endl;

    if (bm == term_bm) {
      ans = min(ans, cost);
    }

    for (int i = 0; i < 4; ++i) {
      int vx = ux + dx[i];
      int vy = uy + dy[i];
      if (CanGo(vx, vy) == false) continue;
      int next_bm = bm;
      if (arr[vx][vy] == '*') next_bm |= (1 << trash[vx][vy]);
      if (visited2[vx][vy][next_bm]) continue;
      visited2[vx][vy][next_bm] = true;
      pq.emplace(-(cost + 1), pair<int, int>(vx, vy), next_bm);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while (true) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        visited[i][j] = false;
        for (int k = 0; k < 1030; ++k) {
          visited2[i][j][k] = false;
        }
      }
    }
    int sx, sy;
    sx = -1;
    cnt = 0;
    cin >> w >> h;
    if (h == 0 && w == 0) break;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> arr[i][j];
        if (sx == -1 && arr[i][j] == 'o') {
          sx = i, sy = j;
          arr[sx][sy] = '.';
        } else if (arr[i][j] == '*') {
          trash[i][j] = cnt;
          cnt++;
        }
      }
    }
    int findable = CountFindable(sx, sy);
    if (findable < cnt) {
      cout << "-1\n";
    } else {
      cout << Solve(sx, sy) << "\n";
    }
  }

  return 0;
}