// Blocked Billboard II
// http://www.usaco.org/index.php?page=viewproblem2&cpid=783

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
  cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2;

  int al = ay2 - ay1;
  int aw = ax2 - ax1;

  int ol = min(ay2, by2) - max(ay1, by1);
  int ow = min(ax2, bx2) - max(ax1, bx1);

  int l = al, w = aw;

  if (ol > 0 && ow > 0) {
    if (ol == al && (ax1 >= bx1 || bx2 >= ax2)) {
      w -= ow;
    }
    if (ow == aw && (ay1 >= by1 || by2 >= ay2)) {
      l -= ol;
    }
  }

  cout << w * l << "\n";

  return 0;
}