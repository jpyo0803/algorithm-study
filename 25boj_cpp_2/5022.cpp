// 연결 
// https://www.acmicpc.net/problem/5022

#include <bits/stdc++.h>

using namespace std;

int n, m;
pair<int, int> a1, a2, b1, b2;

int dist[105][105];
bool path_arr[105][105];
pair<int, int> p[105][105];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool IsOutOfRange(int x, int y) {
  return x < 0 || x > n || y < 0 || y > m;
}

void ResetDistAndParent() {
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dist[i][j] = -1;
      p[i][j] = {-1, -1};
    } 
  }
}

void ResetPath() {
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      path_arr[i][j] = false;
    } 
  }
}

void MarkPath(int x, int y) { 
  path_arr[x][y] = true;
  int nx = p[x][y].first;
  int ny = p[x][y].second;
  if (!(nx == x && ny == y)) {
    MarkPath(nx, ny);
  }
}

int Solve2(pair<int, int> s, pair<int, int> t, vector<pair<int, int>> others) {
  // find and mark minimum path and return cost
  int sx = s.first, sy = s.second;
  int tx = t.first, ty = t.second;

  queue<pair<int, int>> que;
  que.push(s);
  dist[sx][sy] = 0;
  p[sx][sy] = {sx, sy};

  int ans = -1;
  while (que.size()) {
    auto u = que.front();
    que.pop();
    int ux = u.first, uy = u.second;
    
    if (u == t) {
      ans = dist[ux][uy];
      break;
    }

    for (int i = 0; i < 4; ++i) {
      int vx = ux + dx[i], vy = uy + dy[i];
      auto v = make_pair(vx, vy);
      if (IsOutOfRange(vx, vy)) continue;
      if (path_arr[vx][vy]) continue; // path is already used
      if (others[0] == v || others[1] == v) continue;
      if (dist[vx][vy] != -1) continue; // already visited
      dist[vx][vy] = dist[ux][uy] + 1;
      p[vx][vy] = u;
      que.push(v);
    }
  }

  if (ans != -1) {
    MarkPath(tx, ty);
  }
  return ans;
}

int Solve() {
  int ans = -1;
  ResetPath();
  ResetDistAndParent();
  int a1toa2, b1tob2;
  a1toa2 = Solve2(a1, a2, {b1, b2});
  ResetDistAndParent();
  b1tob2 = Solve2(b1, b2, {a1, a2});
  if (a1toa2 != -1 && b1tob2 != -1) {
    if (ans == -1 || a1toa2 + b1tob2 < ans) {
      ans = a1toa2 + b1tob2;
    }
  }

  ResetPath();
  ResetDistAndParent();
  b1tob2 = Solve2(b1, b2, {a1, a2});
  ResetDistAndParent();
  a1toa2 = Solve2(a1, a2, {b1, b2});
  if (a1toa2 != -1 && b1tob2 != -1) {
    if (ans == -1 || a1toa2 + b1tob2 < ans) {
      ans = a1toa2 + b1tob2;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  cin >> a1.first >> a1.second;
  cin >> a2.first >> a2.second;
  cin >> b1.first >> b1.second;
  cin >> b2.first >> b2.second;

  int ans = Solve();
  if (ans == -1) cout << "IMPOSSIBLE\n";
  else cout << ans << "\n";

  return 0;
}