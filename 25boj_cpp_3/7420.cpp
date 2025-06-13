// 맹독 방벽 
// https://www.acmicpc.net/problem/7420

#include <bits/stdc++.h>

using namespace std;

double GetAngle(pair<int, int> v1, pair<int, int> v2) {
  double dot = v1.first * v2.first + v1.second * v2.second;
  double mag1 = sqrt(v1.first * v1.first + v1.second * v1.second);
  double mag2 = sqrt(v2.first * v2.first + v2.second * v2.second);
  return acos(dot / mag1 / mag2);
}

pair<int, int> GetVector(pair<int, int> p1, pair<int, int> p2) {
  return {p2.first - p1.first, p2.second - p1.second};
}

int N, L, x, y;

int CCW(pair<int, int> v1, pair<int, int> v2) {
  int res = v1.first * v2.second - v1.second * v2.first;
  if (res > 0)
    return 1;  // ccw
  else if (res < 0)
    return -1;  // cw
  return 0;     // colinear
}

vector<pair<int, int>> ConvexHull(vector<pair<int, int>> pts) {
  sort(pts.begin(), pts.end());

  vector<pair<int, int>> lh, uh;

  for (int i = 0; i < pts.size(); ++i) {
    while (lh.size() >= 2 &&
           CCW(GetVector(lh[lh.size() - 2], lh[lh.size() - 1]),
               GetVector(lh[lh.size() - 1], pts[i])) <= 0) {
      lh.pop_back();
    }
    lh.push_back(pts[i]);
  }

  for (int i = (int)pts.size() - 1; i >= 0; --i) {
    while (uh.size() >= 2 &&
           CCW(GetVector(uh[uh.size() - 2], uh[uh.size() - 1]),
               GetVector(uh[uh.size() - 1], pts[i])) <= 0) {
      uh.pop_back();
    }
    uh.push_back(pts[i]);
  }

  lh.pop_back();
  for (int i = 0; i < uh.size() - 1; ++i) {
    lh.push_back(uh[i]);
  }
  return lh;
}

long long Solve(const vector<pair<int, int>>& ch) {
  double ans = 0;

  int len = ch.size();

  for (int i = 0; i < len; ++i) {
    int next = (i + 1) % len;
    auto v = GetVector(ch[i], ch[next]);
    ans += sqrt(v.first * v.first + v.second * v.second);

    int prev = i - 1;
    if (prev < 0) prev += len;
    auto v1 = GetVector(ch[i], ch[prev]);
    auto v2 = GetVector(ch[i], ch[next]);
    auto angle = M_PI - GetAngle(v1, v2);
    ans += angle * L;
  }

  return round(ans);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> L;

  vector<pair<int, int>> pts(N);
  for (int i = 0; i < N; ++i) cin >> pts[i].first >> pts[i].second;

  auto ch = ConvexHull(pts);

  cout << Solve(ch) << "\n";

  return 0;
}