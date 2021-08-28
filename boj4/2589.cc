//
// 보물섬
// Link: https://www.acmicpc.net/problem/2589
//

#include <cstdio>
#include <queue>

constexpr int kMax = 50;
constexpr int d[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

using namespace std;
int L, W;

bool map[kMax][kMax];
bool visited[kMax][kMax];

struct Point {
  Point(int _r, int _c, int _move = 0) : r(_r), c(_c), move(_move) {}
  int r, c, move;
};

bool InRange(int x, int y) { return x >= 0 && x < L && y >= 0 && y < W; }

int BFS(int sr, int sc) {
  int ret = 0;

  for (int i = 0; i < L; i++) {
    for (int j = 0; j < W; j++) {
      visited[i][j] = false;
    }
  }
  queue<Point> que;
  que.emplace(sr, sc);
  visited[sr][sc] = true;

  while (!que.empty()) {
    auto p = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int nr = p.r + d[i][0];
      int nc = p.c + d[i][1];
      if (InRange(nr, nc) && map[nr][nc] && !visited[nr][nc]) {
        que.emplace(nr, nc, p.move + 1);
        visited[nr][nc] = true;
        ret = ret < p.move + 1 ? p.move + 1 : ret;
      }
    }
  }
  return ret;
}

int main() {
  scanf("%d%d", &L, &W);
  for (int i = 0; i < L; i++) {
    char row[kMax + 1];
    scanf("%s", row);
    for (int j = 0; j < W; j++) {
      map[i][j] = (row[j] == 'L');
    }
  }

  int ans = 0;
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < W; j++) {
      if (map[i][j]) {
        int ret = BFS(i, j);
        ans = ans < ret ? ret : ans;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}