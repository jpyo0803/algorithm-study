// 직사각형의 합집합
// https://www.acmicpc.net/problem/2185

#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

int Abs(int x) { return x < 0 ? -x : x; }
int Min(int x, int y) { return x < y ? x : y; }
int Max(int x, int y) { return x < y ? y : x; }

struct Segment {
  int x, yl, yh, z;
  Segment(int _x, int _yl, int _yh, int _z) : x(_x), yl(_yl), yh(_yh), z(_z) {}
};

struct Rectangle {
  int x1, y1, x2, y2;
  Rectangle(int _x1, int _y1, int _x2, int _y2) {
    x1 = Min(_x1, _x2);
    x2 = Max(_x1, _x2);
    y1 = Min(_y1, _y2);
    y2 = Max(_y1, _y2);
  }
};

vector<Segment> vs;
vector<Rectangle> rv;

int N, x1, y1, x2, y2;

int sum_tree[20000 * 4];
int count_tree[20000 * 4];

void Update(int n, int nl, int nr, int s, int e, int v) {
  if (nr < s || e < nl) return;

  if (s <= nl && nr <= e) {
    count_tree[n] += v;
  } else {
    int m = (nl + nr) / 2;
    Update(n * 2, nl, m, s, e, v);
    Update(n * 2 + 1, m + 1, nr, s, e, v);
  }

  if (count_tree[n] == 0) {
    if (nl == nr)
      sum_tree[n] = 0;
    else
      sum_tree[n] = sum_tree[n * 2] + sum_tree[n * 2 + 1];
  } else {
    sum_tree[n] = nr - nl + 1;
  }
}

bool Comparator(const Segment& a, const Segment& b) {
  if (a.x == b.x) {
    return a.z < b.z;
  }
  return a.x < b.x;
}

int Solve(int ll, int ul) {
  for (int i = 0; i < 20000 * 4; ++i) {
    sum_tree[i] = count_tree[i] = 0;
  }

  sort(vs.begin(), vs.end(), Comparator);

  int ans = 0;
  for (int i = 0; i < vs.size(); ++i) {
    int prev_dy = sum_tree[1];
    Update(1, ll, ul, vs[i].yl, vs[i].yh, vs[i].z);
    int now_dy = sum_tree[1];
    int prev_ans = ans;
    ans += Abs(now_dy - prev_dy);
  }
  return ans;
}

int main() {
  scanf("%d", &N);
  vs.reserve(2 * N);

  for (int n = 0; n < N; ++n) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    rv.emplace_back(x1, y1, x2, y2);
  }

  int ans = 0;

  int ll = 20000;
  int ul = 0;
  for (auto& rec : rv) {
    vs.emplace_back(rec.x1, rec.y1 + 10000, rec.y2 + 10000 - 1, 1);
    vs.emplace_back(rec.x2 + 1, rec.y1 + 10000, rec.y2 + 10000 - 1, -1);
    ll = Min(ll, rec.y1 + 10000);
    ul = Max(ul, rec.y2 + 10000 - 1);
  }
  ans += Solve(ll, ul);

  ll = 20000;
  ul = 0;
  vs.clear();

  for (auto& rec : rv) {
    vs.emplace_back(rec.y1, rec.x1 + 10000, rec.x2 + 10000 - 1, 1);
    vs.emplace_back(rec.y2 + 1, rec.x1 + 10000, rec.x2 + 10000 - 1, -1);
    ll = Min(ll, rec.x1 + 10000);
    ul = Max(ul, rec.x2 + 10000 - 1);
  }
  ans += Solve(ll, ul);

  printf("%d\n", ans);

  return 0;
}