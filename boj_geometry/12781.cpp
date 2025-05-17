// PIZZA ALVOLOC
// https://www.acmicpc.net/problem/12781

#include <bits/stdc++.h>

using namespace std;

pair<int, int> p1, p2, p3, p4;

int CCW(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
  pair<int, int> v1(p2.first - p1.first, p2.second - p1.second);
  pair<int, int> v2(p3.first - p1.first, p3.second - p1.second);
  int res = v1.first * v2.second - v1.second * v2.first;
  if (res == 0) return 0;
  return res < 0 ? -1 : 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> p1.first >> p1.second;
  cin >> p2.first >> p2.second;
  cin >> p3.first >> p3.second;
  cin >> p4.first >> p4.second;

  int a = CCW(p1, p2, p3) * CCW(p1, p2, p4);
  int b = CCW(p3, p4, p1) * CCW(p3, p4, p2);
  
  cout << ((a < 0 && b < 0) ? 1 : 0) << "\n";

  return 0;
}