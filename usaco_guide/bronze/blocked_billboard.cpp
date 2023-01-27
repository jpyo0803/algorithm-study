// Blocked Billboard
// http://www.usaco.org/index.php?page=viewproblem2&cpid=759

#include <bits/stdc++.h>

using namespace std;

struct Rectangle {
  int x1, y1, x2, y2;

  Rectangle() = default;

  Rectangle(int _x1, int _y1, int _x2, int _y2)
      : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
};

int GetArea(const Rectangle& r) {
  int length = r.y2 - r.y1;
  int width = r.x2 - r.x1;
  if (length < 0 || width < 0) return 0;
  return length * width;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Rectangle a, b, c;
  cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
  cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
  cin >> c.x1 >> c.y1 >> c.x2 >> c.y2;

  int ans = GetArea(a) + GetArea(b) -
            GetArea(Rectangle(max(a.x1, c.x1), max(a.y1, c.y1), min(a.x2, c.x2),
                              min(a.y2, c.y2))) -
            GetArea(Rectangle(max(b.x1, c.x1), max(b.y1, c.y1), min(b.x2, c.x2),
                              min(b.y2, c.y2)));

  cout << ans << "\n";

  return 0;
}