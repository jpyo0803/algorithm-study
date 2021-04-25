// 아기 상어
// https://www.acmicpc.net/problem/16236

#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

struct Point {
  int r, c;
  Point(int _r, int _c) : r(_r), c(_c) {}
};

int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool visited[20][20];
int map[20][20];
int N;

bool InRange(const Point& p) {
  return !(p.r < 0 || p.r >= N || p.c < 0 || p.c >= N);
}

void ResetVisited() {
  for (int r = 0; r < N; r++)
    for (int c = 0; c < N; c++) visited[r][c] = false;
}

bool Compare(const Point& x, const Point& y) {
  if (x.r == y.r) return x.c < y.c;
  return x.r < y.r;
}

int Solve(int sr, int sc) {
  int t = 0, now_t = 0;
  int shark_size = 2;
  int eat_count = 0;
  vector<Point> frontier, next, candidates;

  frontier.emplace_back(sr, sc);
  visited[sr][sc] = true;

  while (!frontier.empty()) {
    next.clear();
    for (auto& u : frontier) {
      if (map[u.r][u.c] > 0 && map[u.r][u.c] < shark_size) {
        candidates.push_back(u);
      }
      for (int i = 0; i < 4; i++) {
        Point v(u.r + d[i][0], u.c + d[i][1]);
        if (!InRange(v) || visited[v.r][v.c] || map[v.r][v.c] > shark_size)
          continue;
        next.push_back(v);
        visited[v.r][v.c] = true;
      }
    }
    if (!candidates.empty()) {
      sort(candidates.begin(), candidates.end(), Compare);
      eat_count++;
      map[candidates[0].r][candidates[0].c] = 0;
      if (eat_count == shark_size) {
        shark_size++;
        eat_count = 0;
      }
      ResetVisited();
      visited[candidates[0].r][candidates[0].c] = true;
      next.clear();
      next.push_back(candidates[0]);
      candidates.clear();
      t = now_t;
    } else {
      now_t++;
    }
    swap(frontier, next);
  }

  return t;
}

int main() {
  scanf("%d", &N);

  int start_r, start_c;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      scanf("%d", &map[r][c]);
      if (map[r][c] == 9) {
        start_r = r;
        start_c = c;
        map[r][c] = 0;
      }
    }
  }

  printf("%d\n", Solve(start_r, start_c));

  return 0;
}
