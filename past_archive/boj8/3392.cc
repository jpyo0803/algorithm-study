// 화성 지도
// https://www.acmicpc.net/problem/3392

#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

struct Segment {
  int x, y_low, y_high;
  bool is_first;

  Segment(int _x, int _y_low, int _y_high, bool _is_first)
      : x(_x), y_low(_y_low), y_high(_y_high), is_first(_is_first) {}
};

int N, x1, y1, x2, y2;
vector<Segment> vertical_segments;

int sum_tree[30000 * 4];
int count_tree[30000 * 4];

void Update(int node, int node_left, int node_right, int start, int end,
            int value) {
  if (node_right < start || end < node_left) return;

  if (start <= node_left && node_right <= end) {
    count_tree[node] += value;
  } else {
    int mid = (node_left + node_right) / 2;
    Update(node * 2, node_left, mid, start, end, value);
    Update(node * 2 + 1, mid + 1, node_right, start, end, value);
  }

  if (count_tree[node] == 0) {
    if (node_left != node_right)
      sum_tree[node] = sum_tree[node * 2] + sum_tree[node * 2 + 1];
    else
      sum_tree[node] = 0;
  } else {
    sum_tree[node] = node_right - node_left + 1;
  }
}

bool Comparator(const Segment& a, const Segment& b) { return a.x < b.x; }

int main() {
  scanf("%d", &N);
  vertical_segments.reserve(2 * N);

  int min_limit = 30000;
  int max_limit = 0;
  for (int n = 0; n < N; ++n) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    vertical_segments.emplace_back(x1, y1, y2 - 1, true);
    vertical_segments.emplace_back(x2, y1, y2 - 1, false);
    min_limit = y1 < min_limit ? y1 : min_limit;
    max_limit = max_limit < y2 - 1 ? y2 - 1 : max_limit;
  }

  sort(vertical_segments.begin(), vertical_segments.end(), Comparator);

  int ans = 0;
  int prev_x = vertical_segments[0].x;
  for (auto& vertical_segment : vertical_segments) {
    int dy = sum_tree[1];
    int dx = vertical_segment.x - prev_x;
    ans += dx * dy;
    prev_x = vertical_segment.x;

    if (vertical_segment.is_first) {
      Update(1, min_limit, max_limit, vertical_segment.y_low,
             vertical_segment.y_high, 1);
    } else {
      Update(1, min_limit, max_limit, vertical_segment.y_low,
             vertical_segment.y_high, -1);
    }
  }

  printf("%d\n", ans);

  return 0;
}