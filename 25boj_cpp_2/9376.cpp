// 탈옥 
// https://www.acmicpc.net/problem/9376

#include <bits/stdc++.h>

using namespace std;

int t, h, w;

char arr[105][105];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool OutOfRange(int x, int y) {
  return x < 0 || x > h + 1 || y < 0 || y > w + 1;
}

vector<vector<int>> Solve(pair<int, int> s) {
  int sx = s.first;
  int sy = s.second;

  vector<vector<int>> dist(h + 2, vector<int>(w + 2, 1e8));
  queue<pair<int, int>> q0, q1;
  q0.emplace(sx, sy);
  dist[sx][sy] = 0;

  while (!q0.empty() || !q1.empty()) {
    pair<int, int> u;
    if (q0.size()) {
      u = q0.front();
      q0.pop();
    } else {
      u = q1.front();
      q1.pop();
    }

    int ux = u.first;
    int uy = u.second;
    int cost = dist[ux][uy];

    for (int i = 0; i < 4; ++i) {
      int vx = ux + dx[i];
      int vy = uy + dy[i];
      if (OutOfRange(vx, vy)) continue;
      if (arr[vx][vy] == '*') continue;

      bool is_door = arr[vx][vy] == '#';
      int next_cost = cost + (is_door ? 1 : 0);
      if (dist[vx][vy] <= next_cost) continue;
      dist[vx][vy] = next_cost;
      if (is_door) {
        q1.emplace(vx, vy);
      } else {
        q0.emplace(vx, vy);
      }
    }
  }

  return dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    pair<int, int> a, b, out;
    out.first = out.second = 0;
    a.first = -1;

    cin >> h >> w;
    for (int i = 0; i <= h + 1; ++i) {
      for (int j = 0; j <= w + 1; ++j) {
        arr[i][j] = '.';
      }
    }

    for (int i = 1; i <= h; ++i) {
      for (int j = 1; j <= w; ++j) {
        cin >> arr[i][j];
        if (arr[i][j] == '$') {
          if (a.first == -1) {
            arr[i][j] = '.';
            a = pair<int, int>(i, j);
          } else {
            arr[i][j] = '.';
            b = pair<int, int>(i, j);
          }
        }
      }
    }

    auto dist_out = Solve(out);
    auto dist_a = Solve(a);
    auto dist_b = Solve(b);

    int ans = dist_out[a.first][a.second] + dist_out[b.first][b.second];

    for (int i = 1; i <= h; ++i) {
      for (int j = 1; j <= w; ++j) {
        if (arr[i][j] == '*') continue;
        int cand = dist_out[i][j] + dist_a[i][j] + dist_b[i][j];
        if (arr[i][j] == '#') cand -= 2;
        if (cand < ans) ans = cand;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}