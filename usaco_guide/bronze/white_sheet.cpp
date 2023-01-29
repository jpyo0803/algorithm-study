// White Sheet (CF)
// https://codeforces.com/contest/1216/problem/C

#include <bits/stdc++.h>

using namespace std;

struct Rect {
  int x1, y1, x2, y2;

  Rect() = default;

  Rect(int _x1, int _y1, int _x2, int _y2)
      : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
};

long long GetOverlapArea(const Rect& a, const Rect& b) {
  long long l = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
  long long w = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
  return l * w;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Rect w, b1, b2;
  cin >> w.x1 >> w.y1 >> w.x2 >> w.y2 >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2 >>
      b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;

  Rect ob(max(b1.x1, b2.x1), max(b1.y1, b2.y1), min(b1.x2, b2.x2),
          min(b1.y2, b2.y2));  // overlaping area of b1 and b2

  long long white_area = (long long)(w.y2 - w.y1) * (w.x2 - w.x1);
  long long covered_area =
      GetOverlapArea(w, b1) + GetOverlapArea(w, b2) - GetOverlapArea(w, ob);
  if (white_area == covered_area) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
  return 0;
}