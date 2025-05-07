// 지민이의 테러 
// https://www.acmicpc.net/problem/1688

#include <bits/stdc++.h>

using namespace std;

int n, x, y;
vector<pair<int, int>> pts;

int CCW(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
  auto v1 = make_pair(p2.first - p1.first, p2.second - p1.second);
  auto v2 = make_pair(p3.first - p1.first, p3.second - p1.second);
  long long res = (long long)v1.first * v2.second - (long long)v1.second * v2.first;
  if (res == 0) return 0;
  return res < 0 ? -1 : 1;
}

bool IsOnSegment(pair<pair<int, int>, pair<int, int>> segment, pair<int, int> pts) {
  int x1 = segment.first.first, x2 = segment.second.first;
  int y1 = segment.first.second, y2 = segment.second.second;
  return (min(x1, x2) <= pts.first && pts.first <= max(x1, x2) 
            && min(y1, y2) <= pts.second && pts.second <= max(y1, y2)) 
            && CCW(segment.first, segment.second, pts) == 0;
}

int Solve(int x, int y) {
  int s = 0;
  for (int i = 0; i < n; ++i) {
    if (IsOnSegment(make_pair(pts[i], pts[(i + 1) % n]), make_pair(x, y))) return 1;

    auto p1x = pts[i].first, p1y = pts[i].second;
    auto p2x = pts[(i + 1) % n].first, p2y = pts[(i + 1) % n].second;
    
    if (min(p1y, p2y) <= y && y <= max(p1y, p2y)) {
      // invariant here, p1y != p2y
      int ccw = CCW(pts[i], pts[(i + 1) % n], make_pair(x, y));
      if (p1y < p2y && ccw > 0) { // upward
        s++;
      } else if (p1y > p2y && ccw < 0) { // downward
        s--;
      }
    }
  }
  return s == 0 ? 0 : 1; // non-zero -> inside, zero -> outside
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    pts.emplace_back(x, y);
  }

  for (int i = 0; i < 3; ++i) {
    cin >> x >> y;
    cout << Solve(x, y) << "\n";
  }

  return 0;
}