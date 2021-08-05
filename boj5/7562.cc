//
// 나이트의 이동
// Link: https://www.acmicpc.net/problem/7562
//

#include <cstdio>
#include <vector>

using namespace std;

int T, I, r1, c1, r2, c2;

bool visited[300][300];

struct Point {
  Point(int _r, int _c) : r(_r), c(_c) {}
  int r, c;
};

int d[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
               {1, -2},  {2, -1},  {2, 1},  {1, 2}};

int Min(int x, int y) { return x < y ? x : y; }

bool InRange(int r, int c) { return r >= 0 && r < I && c >= 0 && c < I; }

int BFS(int r1, int c1, int r2, int c2) {
  vector<Point> frontier, next;
  frontier.emplace_back(r1, c1);
  visited[r1][c1] = true;

  int level = 0;
  while (!frontier.empty()) {
    next.clear();
    for (auto& u : frontier) {
      if (u.r == r2 && u.c == c2) return level;
      for (int i = 0; i < 8; i++) {
        int nr = u.r + d[i][0];
        int nc = u.c + d[i][1];
        if (!InRange(nr, nc)) continue;
        if (visited[nr][nc]) continue;
        next.emplace_back(nr, nc);
        visited[nr][nc] = true;
      }
    }
    swap(frontier, next);
    level++;
  }
  return -1;  // should not reach
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d%d%d%d%d", &I, &r1, &c1, &r2, &c2);
    for (int i = 0; i < I; i++) {
      std::fill(visited[i], visited[i] + I, false);
    }
    printf("%d\n", BFS(r1, c1, r2, c2));
  }
  return 0;
}