// 선분 교차 1
// https://www.acmicpc.net/problem/17386

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

bool IsLineSegment(pair<pair<int, int>, pair<int, int>> l1,
                   pair<pair<int, int>, pair<int, int>> l2) {
  auto a =
      CCW(l1.first, l1.second, l2.first) * CCW(l1.first, l1.second, l2.second);
  auto b =
      CCW(l2.first, l2.second, l1.first) * CCW(l2.first, l2.second, l1.second);
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