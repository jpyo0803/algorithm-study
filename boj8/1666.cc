// 최대 증가 직사각형 집합
// https://www.acmicpc.net/problem/1666

#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

struct Point {
  int x, y, ind;
  bool first;

  Point(int _x, int _y, int _ind, bool _first)
      : x(_x), y(_y), ind(_ind), first(_first) {}

  bool operator<(const Point& other) const {
    if (x == other.x) return first;
    return x < other.x;
  }
};

vector<Point> points;

int N, x1, y1, x2, y2;

int segment_tree[100000 * 4];
int max_record[100000];

int Max(int x, int y) { return x < y ? y : x; }

int Query(int n, int nl, int nr, int ind) {
  if (ind < nl) return 0;
  if (nr <= ind) return segment_tree[n];

  int mid = (nl + nr) / 2;
  return Max(Query(n * 2, nl, mid, ind), Query(n * 2 + 1, mid + 1, nr, ind));
}

void Update(int n, int nl, int nr, int ind, int val) {
  if (ind < nl || nr < ind) return;
  segment_tree[n] = Max(segment_tree[n], val);
  if (nl == nr) return;

  int mid = (nl + nr) / 2;
  Update(n * 2, nl, mid, ind, val);
  Update(n * 2 + 1, mid + 1, nr, ind, val);
}

int main() {
  scanf("%d", &N);
  points.reserve(2 * N);
  for (int n = 0; n < N; ++n) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    points.emplace_back(x1, y1, n, true);
    points.emplace_back(x2, y2, n, false);
  }

  sort(points.begin(), points.end());

  int ans = 0;
  for (auto& point : points) {
    if (point.first) {
      ans = Max(ans,
                max_record[point.ind] = Query(1, 0, 100000, point.y - 1) + 1);
    } else {
      Update(1, 0, 100000, point.y, max_record[point.ind]);
    }
  }

  printf("%d\n", ans);

  return 0;
}