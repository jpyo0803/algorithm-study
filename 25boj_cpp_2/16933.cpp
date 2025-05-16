// 벽 부수고 이동하기 3
// https://www.acmicpc.net/problem/16933

#include <bits/stdc++.h>

using namespace std;

struct Info {
  int x, y, num_break;
  bool is_day;
  int dist;

  Info(int _x, int _y, int _num_break, int _dist, bool _is_day)
    : x(_x), y(_y), num_break(_num_break), dist(_dist), is_day(_is_day) {}
};

int n, m, k;

int dx[5] = {0, 0, 1, -1, 0};
int dy[5] = {1, -1, 0, 0, 0};

string arr[1005];
bool visited[1005][1005][11][2];

bool IsWall(int x, int y) {
  return arr[x][y] == '1';
}

bool OutOfRange(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m;
}

bool IsVisited(const Info& e) {
  return visited[e.x][e.y][e.num_break][e.is_day ? 0 : 1];
}

void MarkVisited(const Info& e) {
  assert(IsVisited(e) == false);
  visited[e.x][e.y][e.num_break][e.is_day ? 0 : 1] = true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) cin >> arr[i];

  queue<Info> que;
  que.emplace(0, 0, 0, 1, true);
  MarkVisited(que.front());

  int ans = 1e9;
  while (que.size()) {
    auto u = que.front();
    que.pop();

    // cout << u.x << " / " << u.y << " / " << u.num_break << " / " << u.dist << endl;

    if (u.x == n - 1 && u.y == m - 1) ans = min(ans, u.dist);

    for (int i = 0; i < 5; ++i) {
      int nx = u.x + dx[i];
      int ny = u.y + dy[i];
      if (OutOfRange(nx, ny)) continue;
      if (!(u.x == nx && u.y == ny) && IsWall(nx, ny)) {
        if (!u.is_day) continue;
        if (u.num_break >= k) continue;
        Info v(nx, ny, u.num_break + 1, u.dist + 1, !u.is_day);
        if (IsVisited(v)) continue;
        MarkVisited(v);
        que.push(v);
      } else {
        Info v(nx, ny, u.num_break, u.dist + 1, !u.is_day);
        if (IsVisited(v)) continue;
        MarkVisited(v);
        que.push(v);
      }
    }
  }

  cout << (ans == 1e9 ? -1 : ans) << "\n";

  return 0;
}