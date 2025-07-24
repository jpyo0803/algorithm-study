// Blocked Billboard (Bronze)
// https://www.acmicpc.net/problem/15463

#include <bits/stdc++.h>

using namespace std;

int Overlap1D(int a, int b, int c, int d) {
  return max(0, min(b, d) - max(a, c));
}

struct Rect {
  Rect(int _x1, int _y1, int _x2, int _y2)
      : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
  int x1, y1, x2, y2;

  int Area() { return (x2 - x1) * (y2 - y1); }

  int Overlap(const Rect& other) const {
    int ox = Overlap1D(x1, x2, other.x1, other.x2);
    int oy = Overlap1D(y1, y2, other.y1, other.y2);
    return ox * oy;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int x1, y1, x2, y2;

  cin >> x1 >> y1 >> x2 >> y2;
  Rect b1(x1, y1, x2, y2);
  cin >> x1 >> y1 >> x2 >> y2;
  Rect b2(x1, y1, x2, y2);
  cin >> x1 >> y1 >> x2 >> y2;
  Rect t(x1, y1, x2, y2);

  int ans = b1.Area() + b2.Area() - b1.Overlap(t) - b2.Overlap(t);
  cout << ans << "\n";

  return 0;
}