// 선분 교차 2
// https://www.acmicpc.net/problem/17387

#include <bits/stdc++.h>

using namespace std;

int CCW(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
  pair<int, int> v1 = {p2.first - p1.first, p2.second - p1.second};
  pair<int, int> v2 = {p3.first - p1.first, p3.second - p1.second};
  long long res =
      (long long)v1.first * v2.second - (long long)v1.second * v2.first;
  if (res > 0)
    return 1;  // CCW
  else if (res < 0)
    return -1;  // CW
  return 0;     // Colinear
}

bool IsPointInBetween(pair<pair<int, int>, pair<int, int>> line, pair<int, int> pt) {
  int x1 = line.first.first;
  int x2 = line.second.first;
  int y1 = line.first.second;
  int y2 = line.second.second;
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);
  return x1 <= pt.first && pt.first <= x2 && y1 <= pt.second && pt.second <= y2;
}

bool IsLineSegment(pair<pair<int, int>, pair<int, int>> l1,
                   pair<pair<int, int>, pair<int, int>> l2) {
  auto a =
      CCW(l1.first, l1.second, l2.first) * CCW(l1.first, l1.second, l2.second);
  auto b =
      CCW(l2.first, l2.second, l1.first) * CCW(l2.first, l2.second, l1.second);
  if (a == 0 && b == 0) {
    return IsPointInBetween(l1, l2.first) || IsPointInBetween(l1, l2.second) || IsPointInBetween(l2, l1.first) || IsPointInBetween(l2, l1.second);
  }
  return (a < 0 && b < 0) || (a == 0 && b < 0) || (a < 0 && b == 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  pair<pair<int, int>, pair<int, int>> l1, l2;
  cin >> l1.first.first >> l1.first.second >> l1.second.first >>
      l1.second.second;
  cin >> l2.first.first >> l2.first.second >> l2.second.first >>
      l2.second.second;

  cout << IsLineSegment(l1, l2) << "\n";

  return 0;
}