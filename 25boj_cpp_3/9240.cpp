// 로버트 후드
// https://www.acmicpc.net/problem/9240

#include <bits/stdc++.h>

using namespace std;

int c;

int CCW(pair<int, int> v1, pair<int, int> v2) {
  int res = v1.first * v2.second - v1.second * v2.first;
  if (res < 0)
    return -1; // cw
  else if (res > 0)
    return 1; // ccw
  return 0;
}

pair<int, int> GetVector(pair<int, int> p1, pair<int, int> p2) {
  return {p2.first - p1.first, p2.second - p1.second};
}

int GetDistanceSqr(pair<int, int> a, pair<int, int> c) {
  int dx = a.first - c.first;
  int dy = a.second - c.second;
  return dx * dx + dy * dy;
}

vector<pair<int, int>> ConvexHull(const vector<pair<int, int>>& pts) {
  vector<pair<int, int>> lower_hull, upper_hull;

  int n = pts.size();
  for (int i = 0; i < n; ++i) {
    while (lower_hull.size() >= 2 &&
           CCW(GetVector(lower_hull[lower_hull.size() - 2],
                         lower_hull[lower_hull.size() - 1]),
               GetVector(lower_hull[lower_hull.size() - 1], pts[i])) <= 0) {
      lower_hull.pop_back();
    }
    lower_hull.push_back(pts[i]);
  }

  for (int i = n - 1; i >= 0; --i) {
    while (upper_hull.size() >= 2 &&
           CCW(GetVector(upper_hull[upper_hull.size() - 2],
                         upper_hull[upper_hull.size() - 1]),
               GetVector(upper_hull[upper_hull.size() - 1], pts[i])) <= 0) {
      upper_hull.pop_back();
    }
    upper_hull.push_back(pts[i]);
  }

  lower_hull.pop_back();
  for (int i = 0; i < upper_hull.size() - 1; ++i) {
    lower_hull.push_back(upper_hull[i]);
  }

  return lower_hull;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> c;
  vector<pair<int, int>> pts(c);
  for (int i = 0; i < c; ++i) cin >> pts[i].first >> pts[i].second;

  sort(pts.begin(), pts.end());

  auto ch = ConvexHull(pts);

  int a = 0, c = 1;
  int ans = 0;

  int len = ch.size();
  do {
    int b = (a + 1) % len;
    int d = (c + 1) % len;
    pair<int, int> ab = GetVector(ch[a], ch[b]);
    pair<int, int> cd = GetVector(ch[c], ch[d]);

    ans = max(ans, GetDistanceSqr(ch[a], ch[c]));

    int ccw = CCW(ab, cd);
    if (ccw >= 0) { // ccw
      c = (c + 1) % len;
    } else { // colinear or cw
      a = (a + 1) % len;
      if (a == 0) break;
    }
  } while (a != c);

  std::cout << std::fixed << std::setprecision(8) << sqrt(ans) << "\n";
  return 0;
}