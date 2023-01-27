// Square Pasture
// http://www.usaco.org/index.php?page=viewproblem2&cpid=663

#include <bits/stdc++.h>

using namespace std;

struct Rect {
  int x1, y1, x2, y2;
};

int GetArea(int x1, int y1, int x2, int y2) {
  int s = max(x2 - x1, y2 - y1);
  return s * s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Rect a, b;
  cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
  cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

  cout << GetArea(min(a.x1, b.x1), min(a.y1, b.y1), max(a.x2, b.x2),
                  max(a.y2, b.y2))
       << "\n";

  return 0;
}