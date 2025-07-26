// Blocked Billboard 2 (Bronze)
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

using namespace std;

int Overlap1D(int a, int b, int c, int d) {
  int x = min(b, d) - max(a, c);
  return max(x, 0);
}

struct Rect {
  int x1, y1, x2, y2;
  Rect() = default;
  Rect(int _x1, int _y1, int _x2, int _y2)
      : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

  int OverlapArea(const Rect& other) {
    int dx = Overlap1D(x1, x2, other.x1, other.x2);
    int dy = Overlap1D(y1, y2, other.y1, other.y2);
    return dx * dy;
  }

  int Area() const { return (x2 - x1) * (y2 - y1); }

  bool IsPointIn(int x, int y) const {
    return (x1 <= x && x <= x2) && (y1 <= y && y <= y2);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int a, b, c, d, e, f, g, h;
  cin >> a >> b >> c >> d;
  cin >> e >> f >> g >> h;

  Rect lm(a, b, c, d);
  Rect cf(e, f, g, h);

  int cnt = 0;
  if (cf.IsPointIn(a, b)) cnt++;
  if (cf.IsPointIn(a, d)) cnt++;
  if (cf.IsPointIn(c, b)) cnt++;
  if (cf.IsPointIn(c, d)) cnt++;

  if (cnt == 4) cout << "0\n";
  else if (cnt == 2) cout << lm.Area() - lm.OverlapArea(cf) << "\n";
  else cout << lm.Area() << "\n";

  return 0;
}