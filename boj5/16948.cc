//
// 데스 나이트
// Link: https://www.acmicpc.net/problem/16948
//

#include <cstdio>
#include <vector>

using namespace std;

constexpr int kMax = 200;

int N, r1, c1, r2, c2;

bool visited[kMax][kMax];

struct Point {
  Point(int _r, int _c) : r(_r), c(_c) {}
  int r, c;
};

int d[6][2] = {{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};

bool BoundaryCheck(int r, int c) {
  return (r >= 0 && r < N && c >= 0 && c < N);
}

int Min(int x, int y) { return x < y ? x : y; }

int BFS(int sr, int sc, int er, int ec) {
  vector<Point> frontier, next;

  frontier.emplace_back(sr, sc);
  visited[sr][sc] = true;

  int level = 0;
  while (!frontier.empty()) {
    next.clear();
    for (auto& u : frontier) {
      if (u.r == er && u.c == ec) return level;
      for (int i = 0; i < 6; i++) {
        int vr = u.r + d[i][0];
        int vc = u.c + d[i][1];
        if (!BoundaryCheck(vr, vc)) continue;
        if (visited[vr][vc]) continue;
        visited[vr][vc] = true;
        next.emplace_back(vr, vc);
      }
    }
    level++;
    swap(frontier, next);
  }
  return -1;
}

int main() {
  scanf("%d%d%d%d%d", &N, &r1, &c1, &r2, &c2);
  printf("%d\n", BFS(r1, c1, r2, c2));
  return 0;
}