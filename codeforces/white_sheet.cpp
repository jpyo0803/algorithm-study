// C. White Sheet
// https://codeforces.com/contest/1216/problem/C

#include <bits/stdc++.h>

using namespace std;

struct R {
  int x1, y1, x2, y2;

  R() { cin >> x1 >> y1 >> x2 >> y2; }

  long long Area() {
    long long dx = x2 - x1;
    long long dy = y2 - y1;
    // if at least one of them is neg, it means one of blacks entirely covered white
    if (dx < 0 || dy < 0) return 0;
    return dx * dy;
  }

  void Cut(const R& other) {
    if (other.x1 <= x1 && x2 <= other.x2) {
      if (other.y1 <= y1 && y1 <= other.y2) {
        y1 = other.y2;
      } else if (other.y1 <= y2 && y2 <= other.y2) {
        y2 = other.y1;
      }
    }
    if (other.y1 <= y1 && y2 <= other.y2) {
      if (other.x1 <= x1 && x1 <= other.x2) {
        x1 = other.x2;
      } else if (other.x1 <= x2 && x2 <= other.x2) {
        x2 = other.x1;
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  R w;
  R b1;
  R b2;

  w.Cut(b1);
  w.Cut(b2);

  if (w.Area() > 0)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}