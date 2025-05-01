// CCW
// https://www.acmicpc.net/problem/11758

#include <bits/stdc++.h>

using namespace std;

pair<int, int> GetVector(pair<int, int> x1, pair<int, int> x2) {
  return {x2.first - x1.first, x2.second - x1.second};
}

int CCW(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
  auto v1 = GetVector(p1, p2);
  auto v2 = GetVector(p1, p3);
  int res = v1.first * v2.second - v1.second * v2.first;
  if (res > 0) return 1;
  else if (res < 0) return -1;
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<pair<int, int>> pts(3);;
  for (int i = 0; i < 3; ++i) cin >> pts[i].first >> pts[i].second;

  cout << CCW(pts[0], pts[1], pts[2]) << "\n";

  return 0;
}