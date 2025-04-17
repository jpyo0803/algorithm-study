// 거울 설치
// https://www.acmicpc.net/problem/2151

/*
  BFS (deque), when ! is encountered, make it go stright or \ or /
  Dont need to keep track of mirrors set before as using a mirror twice is not
  optimal sol.
*/

#include <bits/stdc++.h>

using namespace std;

int n;

char arr[55][55];
int sx = -1, sy;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cost[55][55][4];

bool OutOfRange(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
      if (sx == -1 && arr[i][j] == '#') {
        sx = i, sy = j;
      }
      for (int k = 0; k < 4; ++k) {
        cost[i][j][k] = 1e9;
      }
    }
  }

  // BFS with pos, dir, cost
  deque<tuple<pair<int, int>, int, int>> dq;
  for (int i = 0; i < 4; ++i) {
    dq.emplace_back(pair<int, int>(sx, sy), i, 0);
    // visited[sx][sy][i] = true;
  }

  int ans = -1;
  while (dq.empty() == false) {
    auto e = dq.front();
    dq.pop_front();

    int ux = get<0>(e).first;
    int uy = get<0>(e).second;

    int udir = get<1>(e);
    int ucost = get<2>(e);

    if (arr[ux][uy] == '#' && !(ux == sx && uy == sy)) {
      ans = ucost;
      break;
    }

    int vx, vy;
    vx = ux + dx[udir];
    vy = uy + dy[udir];
    if (OutOfRange(vx, vy) == false && arr[vx][vy] != '*' &&
        cost[vx][vy][udir] > ucost) {
      cost[vx][vy][udir] = ucost;
      dq.emplace_front(pair<int, int>(vx, vy), udir, ucost);
    }
    if (arr[ux][uy] == '!') {
      int vdir;

      // mirror type '/'
      if (udir == 0)
        vdir = 3;  // E(0) to N(3)
      else if (udir == 1)
        vdir = 2;  // W(1) to S(2)
      else if (udir == 2)
        vdir = 1;  // S(2) to W(1)
      else
        vdir = 0;  // N(3) to E(0)

      vx = ux + dx[vdir];
      vy = uy + dy[vdir];

      if (OutOfRange(vx, vy) == false && arr[vx][vy] != '*' &&
          cost[vx][vy][vdir] > ucost + 1) {
        cost[vx][vy][vdir] = ucost + 1;
        dq.emplace_back(pair<int, int>(vx, vy), vdir, ucost + 1);
      }

      // mirror type '\'
      if (udir == 0)
        vdir = 2;  // E(0) to S(2)
      else if (udir == 1)
        vdir = 3;  // W(1) to N(3)
      else if (udir == 2)
        vdir = 0;  // S(2) to E(0)
      else
        vdir = 1;  // N(3) to W(1)

      vx = ux + dx[vdir];
      vy = uy + dy[vdir];

      if (OutOfRange(vx, vy) == false && arr[vx][vy] != '*' &&
          cost[vx][vy][vdir] > ucost + 1) {
        cost[vx][vy][vdir] = ucost + 1;
        dq.emplace_back(pair<int, int>(vx, vy), vdir, ucost + 1);
      }
    }
  }

  cout << ans << "\n";

  return 0;
}